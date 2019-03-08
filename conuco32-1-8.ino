//#define ESP32

#define INITFAB false    // si true, se resetea a fábrica, si false no se hace nada
#define versinst 2000    // primera versión ESP32 
#define debug true
#define debugwifi false

#include "commontexts.h"              // include
#include <IoTtweetESP32.h>            // Local
#include "defines.h"                  // include
#include "bombacalor.h"               // include
#include "variables.h"                // include

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Update.h>  s
#include <ESPmDNS.h>
#include <ESP8266FtpServer.h>
#include "Time.h"                     // Local
#include "TimeLib.h"                  // Local
#include "FS.h"
#include "SPIFFS.h"
#include <HTTPClient.h>                // Local
#include "RCSwitch.h"                 // Local
#include "OneWire.h"                  // Local
#include "DallasTemperature.h"        // Local
#include "DHTesp.h"                   // Local
#include <Adafruit_BMP085.h>          // Local
#include <ESP32httpUpdate.h>  // Local
#include "LiquidCrystal_I2C.h"        // Local
#include <PubSubClient.h>
#include <ModbusMaster.h>             // Local
#include <WiFiUdp.h>
#include <NTPClient.h>                // Local

FtpServer ftpSrv;   //set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial
WebServer server(88); 
IoTtweetESP32 myiot;       //naming your devices
RCSwitch mySwitch = RCSwitch();
DHTesp dht[2];
Adafruit_BMP085 bmp085;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Display LCD 2x16 azul
WiFiClient espClient;
PubSubClient PSclient(espClient);
ModbusMaster MBnode;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, urlNTPserverpool, 3600, 60000);
OneWire owire(owPin);   DallasTemperature sensors0(&owire);
//ESP8266HTTPUpdateServer httpUpdater;

#include "basicfunctions.h"            // include
#include "ajaxcode.h"                  // include
#include "htmlFunctions.h"             // include
#include "conuco32.h"                  // include
#include "jsonfunctions.h"             // include
#include "main.h"                      // include

void initSPIFSS(boolean testfiles)
{
  if (SPIFFS.begin(false)) Serial.println("SPIFSS OK"); else  Serial.println("SPIFSS ERROR");
  File dir=SPIFFS.open(barra);
  File file=dir.openNextFile();
  if (testfiles) { while (file) { Serial.print(file.name()); Serial.print(b); Serial.println(file.size()); file=dir.openNextFile(); }}
}

void initDS18B20()
{
  sensors0.begin();  
  sensors0.setResolution(conf.prectemp);  
  nTemp=sensors0.getDeviceCount();  
  
  dPrint(t(sondastemp)); dPrint(dp); dPrintI(nTemp);dPrint(crlf);
  dPrint(b); dPrint(t(Modo)); dPrint(dp);
  dPrint((sensors0.isParasitePowerMode())?c(tparasite):c(tpower)); dPrint(crlf);
  for (byte i=0; i<nTemp; i++)       {
    if (sensors0.getAddress(addr1Wire[i], i))    {
      dPrint(b);
      for (uint8_t j=0; j<8; j++) { if (addr1Wire[i][j]<16) dPrint(cero); Serial.print(addr1Wire[i][j], HEX); }
      dPrint(crlf);      }     }
}

void initWiFi()
{
  // Init WiFi
  if (conf.wifimode==0) WiFi.mode(WIFI_STA);
  else if (conf.wifimode==1) WiFi.mode(WIFI_AP);
  else if ((conf.wifimode==2) or (conf.wifimode==12)) WiFi.mode(WIFI_AP_STA);
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);
  dPrint(t(wifimodet)); dPrint(dp); dPrintI(conf.wifimode); dPrint(crlf);
  dPrint(c(MAC)); dPrint(dp); dPrint(WiFi.softAPmacAddress()); dPrint(crlf);
  for (byte i=0; i<6; i++) {
    WiFi.softAPmacAddress().substring(i*3,i*3+2).toCharArray(conf.EEmac[i], 3);
    strcat(mac, conf.EEmac[i]);
    }
  if ((conf.wifimode==1) || (conf.wifimode==2) || (conf.wifimode==12)) // AP o AP+STA
    {
    WiFi.channel(conf.canalAP);
    WiFi.softAP(conf.ssidAP, conf.passAP, conf.canalAP, false);
    dPrint(t(canal)); dPrint(dp); dPrintI(WiFi.channel()); dPrint(crlf);
    dPrint(c(tIP)); dPrint(dp); Serial.print(WiFi.softAPIP()); dPrint(crlf);
    }
  if ((conf.wifimode==0) || (conf.wifimode==2) || (conf.wifimode==12)) // STA o AP+STA
    {
    dPrint(t(staticip));  dPrint(dp); dPrint(conf.staticIP?t(SI):t(NO)); dPrint(coma);
    if (conf.staticIP==1) { dPrint(WiFi.config(conf.EEip, conf.EEgw, conf.EEmask, conf.EEdns, conf.EEdns2)==1?ok:c(terror)); }
    dPrint(crlf);
    WiFi.begin(conf.ssidSTA, conf.passSTA, true);
    if (debugwifi) Serial.setDebugOutput(true);
    byte cont = 0;
    dPrint(t(conectando)); dPrint(b); dPrint(conf.ssidSTA); dPrint(barra); dPrint(conf.passSTA); dPrint(b);
    while ((!WiFi.isConnected()) && (cont++ < 20))  { delay(1000); dPrint(punto); }
    dPrint(crlf); dPrint(t(tconectado)); dPrint(b); dPrint(WiFi.isConnected()?ok:c(terror)); dPrint(crlf);
    dPrint(c(tIP)); dPrint(dp); Serial.print(WiFi.localIP()); dPrint(crlf);
    dPrint(c(tport)); dPrint(dp); Serial.print(88); dPrint(crlf);
    }
}

void connectWiFi()
{
  // Wait for connection
  byte cont=0;
  while ((!WiFi.isConnected()) && (cont++<20))  { delay(500); dPrint(punto); }
  Serial.println();
  Serial.print("Connected to ");  Serial.println(conf.ssidSTA);
  Serial.print("IP address: ");  Serial.println(WiFi.localIP());
  if (MDNS.begin("esp32")) { Serial.println("MDNS responder started"); }
  ///// Time
  timeClient.begin();
  if (WiFi.isConnected()) {
    timeClient.setTimeOffset(7200);
    if (timeClient.update() == 1) {countfaulttime = 0; setTime(timeClient.getEpochTime()); }
    }
}

void initFTP()
{
  ftpSrv.begin(admin,admin);    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
}

void initSerial()
{
  Serial.begin(115200);  delay(10);
}

void initPins()
{
  for (byte i=0;i<maxED;i++) pinMode(edPin[i],INPUT);
  for (byte i=0;i<maxSD;i++) pinMode(sdPin[i],OUTPUT);
  // Setup input pins
//  Serial.print("Modo ED:"); Serial.println(conf.modo45);
  if (conf.modo45==0) {         //Entradas digitales ON/OFF
    for (byte i=0;i<maxED;i++) pinMode(edPin[i],INPUT); }
//  else if (conf.modo45==1) {    // I2C
//    Serial.print(i2c); Serial.print(b); Serial.println(c(modet));
//    Wire.begin(edPin[0], edPin[1]);
//    if (!bmp085.begin()) { Serial.print(b);  Serial.println(BMP085notfound);    }  }
//  else if (conf.modo45==2) {    // modbus
//    Serial.print(modbust); Serial.print(b); Serial.println(c(modet));
//    //    SoftSerial.begin(modbusbaud);
//    //    SoftSerial.setTransmitEnablePin(rs485enpin);
//    //    MBnode.begin(1, SoftSerial);
//    pinMode (edPin[0], INPUT_PULLUP);
//    pinMode (edPin[1], OUTPUT);  }
//  for (byte i=0;i<2;i++) if (conf.tipoED[i]==1) dht[i].setup(edPin[i]);
}

void ICACHE_FLASH_ATTR setup(void) {
  initSerial();
  initPins();
  initSPIFSS(false);
  readconf();  //  saveconf();
  initDS18B20();
  initWiFi();
  connectWiFi();
  initFTP(); 
  initHTML();
  server.begin();  Serial.println("HTTP server started");
}

void loop(void) {
//  if (conf.ftpenable) ftpSrv.handleFTP();        //make sure in loop you call handleFTP()!!  
  ftpSrv.handleFTP();          
  server.handleClient();

  leevaloresDIG();
  //////////////////////////////////////////////////////////////////////////////////////////
  if ((millis() > (mact10 + (conf.peractrem * 1000))))  // tareas que se hacen cada "peractrem" segundos
    {
    tini=millis();
    leevaloresOW();

    if ((millis()-tini)>5000) {printhora(); Serial.print(F(" 10 SEG:")); Serial.println(millis()-tini);}
    mact10 = millis();
    }
  if (conf.modohp==1) procesaHP();
  
}

