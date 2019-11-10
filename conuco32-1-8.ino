
#define INITFAB false    // si true, se resetea a fábrica, si false no se hace nada
#define versinst 2028    // primera versión ESP32 
#define debug true
#define debugwifi false

#include "commontexts.h"              // setupio

#include <IoTtweetESP32.h>            // Local
#include "defines.h"                  // include
#include "variables.h"                // include

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Update.h>  
#include <ESPmDNS.h>
#include <ESP8266FtpServer.h>
#include "Time.h"                     // Local 
#include "TimeLib.h"                  // Localc
#include "FS.h"
#include "SPIFFS.h"
#include <HTTPClient.h>               
#include <RCSwitch.h>                 // Local
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
//#include <ResponsiveAnalogRead.h>
///////////////////////////////
#include <Thermistor.h>
#include <NTC_Thermistor.h>
//#define SENSOR_PIN             A1
#define SENSOR_PIN             ADC0
#define REFERENCE_RESISTANCE   8000
#define NOMINAL_RESISTANCE     100000
#define NOMINAL_TEMPERATURE    25
#define B_VALUE                3950
Thermistor* thermistor;
//////////////////////////////////////////

FtpServer ftpSrv;   //set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial
WebServer server(conf.webPort); 
IoTtweetESP32 myiot;       //naming your devices
RCSwitch mySwitch = RCSwitch();
DHTesp dht[maxDHT];
Adafruit_BMP085 bmp085;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Display LCD 2x16 azul
WiFiClient espClient;
PubSubClient PSclient(espClient);
ModbusMaster MBnode;
WiFiUDP ntpUDP;
//ResponsiveAnalogRead analog0(4, true);
//ResponsiveAnalogRead analog1(27, true);

//NTPClient timeClient(ntpUDP, urlNTPserverpool, 3600, 60000);
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org");

OneWire owire(owPin);   DallasTemperature sensors0(&owire);

#include "basicfunctions.h"            // include
#include "ajaxcode.h"                  // include
#include "htmlFunctions.h"             // include
#include "conuco32.h"                  // include
#include "jsonfunctions.h"             // include
#include "main.h"                      // include
#include "bombacalor.h"               // include

void initSPIFSS(boolean testfiles, boolean format)
{
  if (SPIFFS.begin(format)) Serial.println("SPIFSS OK"); else  Serial.println("SPIFSS ERROR");
  File dir=SPIFFS.open(barra);
  File file=dir.openNextFile();
  if (testfiles) { while (file) { Serial.print(file.name()); Serial.print(b); Serial.println(file.size()); file=dir.openNextFile(); }}
}

void initDS18B20()
{
  sensors0.begin();  
  sensors0.setResolution(conf.prectemp);  
  nTemp=sensors0.getDeviceCount(); if (nTemp>maxTemp) nTemp=maxTemp;
  dPrint(t(sondastemp)); dPrint(dp); dPrintI(nTemp);dPrint(crlf); dPrint(b); dPrint(t(Modo)); dPrint(dp);
  dPrint((sensors0.isParasitePowerMode())?c(tparasite):c(tpower)); dPrint(crlf);
  for (byte i=0; i<nTemp; i++)       {
    if (sensors0.getAddress(addr1Wire[i], i))    {
      dPrint(b);
      for (uint8_t j=0; j<8; j++) { if (addr1Wire[i][j]<16) dPrint(cero); Serial.print(addr1Wire[i][j], HEX); }
      dPrint(crlf);      }     }
}

void initEntAna() { for (byte i=0;i<maxEA;i++) pinMode(anaPin[i], INPUT);  }

void initEntDig() { for (byte i=0;i<maxED;i++) pinMode(edPin[i], INPUT);  }

void initSalDig()
  {
  for (byte i=0; i<maxSD; i++)
    {
    pinMode(sdPin[i],OUTPUT);
    digitalWrite(sdPin[i],valorpin[conf.valinic[i]==2?getbit8(conf.MbC8,i):conf.valinic[i]]);
    }
  }
void initbmp085()
{
  if (bmp085.begin()) {bmp085enabled=true; Serial.println(c(BMP085OK));} else { Serial.print(b);  Serial.println(c(BMP085notfound));  }  
}


void initWiFi()
{
  // Init WiFi
  if (conf.wifimode>2) conf.wifimode=2;
  if (conf.wifimode==0) WiFi.mode(WIFI_STA);
  else if (conf.wifimode==1) WiFi.mode(WIFI_AP);
  else if (conf.wifimode==2) WiFi.mode(WIFI_AP_STA);
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
    if (conf.staticIP == 1)
      {
      WiFi.config(conf.EEip, conf.EEgw, conf.EEmask, conf.EEdns, conf.EEdns2);
      }
    for (byte i=0;i<4;i++) {Serial.print(conf.EEdns[i]); Serial.print(".");}
    dPrint(crlf);
    WiFi.begin(conf.ssidSTA, conf.passSTA, true);
    if (debugwifi) Serial.setDebugOutput(true);
    byte cont = 0;
    dPrint(t(conectando)); dPrint(b); dPrint(conf.ssidSTA); dPrint(barra); dPrint(conf.passSTA); dPrint(b);
    while ((!WiFi.isConnected()) && (cont++ < 20))  { delay(1000); dPrint(punto); }
    dPrint(crlf); dPrint(t(tconectado)); dPrint(b); dPrint(WiFi.isConnected()?ok:c(terror)); dPrint(crlf);
    dPrint(c(tIP)); dPrint(dp); Serial.print(WiFi.localIP()); dPrint(crlf);
    dPrint(c(tport)); dPrint(dp); Serial.print(conf.webPort); dPrint(crlf);
    Serial.print("ESP Mac Address: ");    Serial.println(WiFi.macAddress());
    Serial.print("Subnet Mask: ");    Serial.println(WiFi.subnetMask());
    Serial.print("Gateway IP: ");    Serial.println(WiFi.gatewayIP());
    Serial.print("DNS: ");    Serial.println(WiFi.dnsIP());
    }
}

void initTime()
{
  ///// Time
  timeClient.begin();
  if (WiFi.isConnected()) {
    timeClient.setTimeOffset(7200);
    if (timeClient.update()==1) 
      {countfaulttime=0; setTime(timeClient.getEpochTime()); }
    else
      {
      Serial.print("timeclient.update:"); Serial.println(timeClient.update());
      }
    }
}

void initFTP()
{
  ftpSrv.begin(admin,admin);    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
}

void initSerial() { Serial.begin(115200);  delay(10); }

void asignPins()
{
  // reasignación de GPIOs según leído en fichero conf
//  for (byte i=0;i<maxED;i++) { edPin[i]=conf.ngpio[i+10]; }
//  for (byte i=0;i<maxSD;i++) { sdPin[i]=conf.ngpio[i+14]; }

}

void initWebserver() { server.begin();  Serial.println("HTTP server started"); }
void initPubSub() { PSclient.setServer(conf.mqttserver, 1883); PSclient.setCallback(mqttcallback); }

void init433()
{
  pinMode(RX433,INPUT_PULLUP);
  mySwitch.enableReceive(RX433);  // Receiver on interrupt 32 => that is pin #32,
//  mySwitch.enableTransmit(tx433);  // 15
}

void initLCD()
{
  if (conf.I2Cenabled==1) { lcd.init();  lcd.backlight(); lcdshowstatus(); }
}

void initgpiosvar()
{
for (byte i=0;i<maxgpiovar;i++)
  {
    
  }
}

void leerConf()
{
  if (readconf()<sizeof(conf)) saveconf();
  if ((conf.netseg==0) || (conf.netseg==255)) conf.netseg=1;      // provisional
}

void initIFTTT()
{
  if (WiFi.isConnected()) {
    if (conf.iftttenable) 
      {
      strcpy(auxdesc,itoa(WiFi.localIP()[0],buff,10)); 
      for (byte i=1;i<=3;i++) { strcat(auxdesc,"."); strcat(auxdesc,itoa(WiFi.localIP()[i],buff,10)); }
      ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, auxdesc, conf.myippub);
      }
//    if (conf.modomyjson==1) putmyjson();
//    if (conf.mododweet==1) postdweet(mac);
//    if (conf.iottweetenable==1) postIoTweet();
  }
}

void ICACHE_FLASH_ATTR setup(void) {
  initSerial();
  initSPIFSS(true,true);
  if (INITFAB) initFab();   // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  leerConf();  //  saveconf();
  asignPins();
  initDS18B20();
  initEntDig();
  initSalDig();
  initWiFi();
  initFTP(); 
  initHTML();
  initTime();
  initWebserver();
  initPubSub();
  initIFTTT();
  checkMyIP();  dPrint(t(ippublica)); dPrint(dp); dPrint(conf.myippub); dPrint(crlf);
  initLCD();
//  initbmp085();
//  init433();
  initgpiosvar();
  thermistor = new NTC_Thermistor(SENSOR_PIN,REFERENCE_RESISTANCE,NOMINAL_RESISTANCE,NOMINAL_TEMPERATURE,B_VALUE);  
}

void testChange()
{
  if (statusChange) {
    lcdshowstatus();
    if (conf.modomyjson==1) putmyjson();
    if (conf.mododweet==1) postdweet(mac);
    if (conf.iottweetenable==1) postIoTweet();
    actualizamasters();
    }
  if ((iftttchange[0]>0) || (iftttchange[1]>0))
    {
    for (byte i=0;i<maxSD;i++)
      {
      if (getbit8(iftttchange,i)==1)    // SD i
        {
        if ((getbit8(conf.iftttpinSD,i)==1) && (getbit8(conf.MbC8,i)==1))
          ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, readdescr(filedesclocal,i+14,20), textonoff(1));
        if ((getbit8(conf.iftttpinSD,i+8)==1) && (getbit8(conf.MbC8,i)==0))
          ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, readdescr(filedesclocal,i+14,20), textonoff(0));
        }
      }
    for (byte i=0;i<maxED;i++)
      {
      if (getbit8(iftttchange,i+8)==1)     // ED i
        {
        if ((getbit8(conf.iftttpinED,i)==1) && (getbit8(conf.MbC8,i+8)==1))     // en ON 
          ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, readdescr(filedesclocal,i+10,20), textonoff(1));
        if ((getbit8(conf.iftttpinED,i+8)==1) && (getbit8(conf.MbC8,i+8)==0))     // en OFF
          ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, readdescr(filedesclocal,i+10,20), textonoff(0));
        }
      }
    iftttchange[0]=0;
    }
}

void execcom()
{
  String command, param;
  command=sinput.substring(0,sinput.indexOf(","));
  param=sinput.substring(sinput.indexOf(",")+1);
//  Serial.print("comando/param: "); Serial.print(command);Serial.print("/");Serial.println(param);
  if (command=="reset") ESP.restart();
  else if (command=="files")  
    { 
    File dir=SPIFFS.open(barra);
    File file=dir.openNextFile();
    while (file) { Serial.print(file.name()); Serial.print(b); Serial.println(file.size()); file=dir.openNextFile(); }
    Serial.print("files ");  Serial.println(checkfiles()?"OK":"ERROR");
    }
  else if ((command=="help") || (command=="h"))
    {   
    Serial.println("reset");
    Serial.println("files");
    Serial.println("st");
    Serial.println("id,iddevice");
    Serial.println("alias,aliasdevice");
    Serial.println("instal,instaldevice");
    Serial.println("ssid,SSIDname");
    Serial.println("pass,SSIDpass");
    Serial.println("seg,segnet");
    }
  else if (command=="st")  
    {   
    Serial.print("DEV:"); Serial.println(conf.iddevice);
    Serial.print("alias:"); Serial.println(conf.aliasdevice);
    Serial.print("IP:"); Serial.println(WiFi.localIP());
    Serial.print("mask:"); Serial.println(WiFi.subnetMask());
    Serial.print("GW:"); Serial.println(WiFi.gatewayIP());
    Serial.print("SSID:"); Serial.println(conf.ssidSTA);
    Serial.print("Pass:"); Serial.println(conf.passSTA);
    Serial.print("Conn:"); Serial.println(WiFi.isConnected()?ok:c(terror));
    Serial.println("Done");
    }
  else if (command=="id") { conf.iddevice=param.toInt(); conf.EEip[3]=conf.iddevice; param.toCharArray(conf.mqttpath[2],10); saveconf(); Serial.println("Done");}
  else if (command=="alias") { param.toCharArray(conf.aliasdevice,20); saveconf(); }
  else if (command=="instal") { param.toCharArray(conf.instname,10); param.toCharArray(conf.mqttpath[1],10);saveconf(); Serial.println("Done");}
  else if (command=="ssid") { param.toCharArray(conf.ssidSTA,20); saveconf();Serial.println("Done"); }
  else if (command=="pass") { param.toCharArray(conf.passSTA,20); saveconf(); Serial.println("Done");}
  else if (command=="seg") { conf.netseg=param.toInt(); conf.EEip[2]=conf.netseg; conf.EEgw[2]=conf.netseg; saveconf(); Serial.println("Done");}
  else { Serial.println("Command not found"); }
}

//void execcom()
//{
//  String command, param;
//  boolean hecho=false;
//  command = sinput.substring(0, sinput.indexOf(","));
//  param = sinput.substring(sinput.indexOf(",") + 1);
//  //  Serial.print("comando/param: "); Serial.print(command);Serial.print("/");Serial.println(param);
//  if (command == "reset") 
//    ESP.restart();  
////  else if (command == "resetw") 
////    reinitWiFi();
//  else if (command == "resetf") 
//    initFab();
////  else if (command == "files")
////    {
////    Dir dir = SPIFFS.openDir(barra);
////    while (dir.next())  {
////      Serial.print(dir.fileName());
////      Serial.print(b);
////      File f = dir.openFile(letrar);
////      Serial.println(f.size());
////      }
////    Serial.print("files ");  Serial.println(checkfiles() ? "OK" : "ERROR");
////    }
//  else if ((command == "help") || (command == "h"))
//    {
//    Serial.println("reset");
//    Serial.println("resetw");
//    Serial.println("resetf");
//    Serial.println("wifim");
//    Serial.println("files");
//    Serial.println("st");
//    Serial.println("ssidap,SSIDnameAP");
//    Serial.println("passap,SSIDpassAP");
//    }
//  else if (command == "st")
//    {
//    Serial.print("DEV:"); Serial.println(conf.iddevice);
//    Serial.print("alias:"); Serial.println(conf.aliasdevice);
//    Serial.print("IP:"); for (byte i=0;i<4;i++) {Serial.print(conf.EEip[i]);Serial.print(punto); } Serial.println();
//    Serial.print("mask:"); for (byte i=0;i<4;i++) {Serial.print(conf.EEmask[i]); Serial.print(punto);}Serial.println();
//    Serial.print("GW:");for (byte i=0;i<4;i++) {Serial.print(conf.EEgw[i]);Serial.print(punto); }Serial.println();
//    Serial.print("SSID:"); Serial.println(conf.ssidSTA);
//    Serial.print("Pass:"); Serial.println(conf.passSTA);
//    Serial.print("SSIDAP:"); Serial.println(conf.ssidAP);
//    Serial.print("PassAP:"); Serial.println(conf.passAP);
//    Serial.print("Conn:"); Serial.println(WiFi.isConnected() ? ok : c(terror));
//    Serial.println("Done");
//    }
//  else if (command == "id") {
//    conf.iddevice = param.toInt();
//    conf.EEip[3] = conf.iddevice;
//    param.toCharArray(conf.mqttpath[2], 10);
//    saveconf(); hecho=true;
//    }
//  else if (command == "alias") {
//    param.toCharArray(conf.aliasdevice, 20);
//    saveconf(); hecho=true;
//    }
//  else if (command == "instal") {
//    param.toCharArray(conf.instname, 10);
//    param.toCharArray(conf.mqttpath[1], 10);
//    saveconf(); hecho=true;
//    }
//  else if (command == "ssid") {
//    param.toCharArray(conf.ssidSTA, 20);
//    saveconf(); hecho=true;
//    }
//  else if (command == "pass") {
//    param.toCharArray(conf.passSTA, 20);
//    saveconf(); hecho=true;
//    }
//  else if (command == "ssidap") {
//    param.toCharArray(conf.ssidAP, 20);
//    saveconf(); hecho=true;
//    }
//  else if (command == "passap") {
//    param.toCharArray(conf.passAP, 20);
//    saveconf(); hecho=true;
//    }
//  else if (command == "wifim") {
//    conf.wifimode = param.toInt();
//    saveconf(); hecho=true;
//    }
//  else if (command == "ip0") {
//    conf.EEip[0] = param.toInt();
//    conf.EEgw[0] = param.toInt();
//    saveconf(); hecho=true;
//    }
//  else if (command == "ip1") {
//    conf.EEip[1] = param.toInt();
//    conf.EEgw[1] = param.toInt();
//    saveconf(); hecho=true;
//    }
//  else if (command == "ip2") {
//    conf.EEip[2] = param.toInt();
//    conf.EEgw[2] = param.toInt();
//    saveconf(); hecho=true;
//    }
//  else if (command == "ip3") {
//    conf.EEip[3] = param.toInt();
//    conf.EEgw[3] = 1;
//    saveconf(); hecho=true;
//    }
//  else if (command == "seg") {
//    conf.netseg = param.toInt();
//    conf.EEip[2] = conf.netseg;
//    conf.EEgw[2] = conf.netseg;
//    saveconf(); hecho=true;
//    }
//  Serial.println(hecho?"Done":"Command not found");
//}

void task1()
{
  tini=millis();
  countfaulttime++;   // si se hace mayor que TempDesactPrg,desactiva ejecucion programas dependientes de fecha
  leevaloresAN();
  // gestión botón reset InitFabrica
  procesaeventos();
  procesaTimeMax();
  for (byte j=0; j<maxsalrem; j++)
    if (conf.idsalremote[j]>0)
      if ((conf.senalrem[j]==6) || (conf.senalrem[j]==7)) contaremote[j]++;
  if (WiFi.isConnected()) { testChange();  }
  mact1 = millis();
  // Reads temperature
//  const double celsius = thermistor->readCelsius();
//  const double kelvin = thermistor->readKelvin();
//  const double fahrenheit = thermistor->readFahrenheit();
//  // Output of information
//  Serial.print("Temperature: ");  
//  Serial.print(celsius);  Serial.print(" C, ");  
//  Serial.print(kelvin);  Serial.print(" K, ");  
//  Serial.print(fahrenheit);  Serial.println(" F");
}

void taskvar()
{
  tini=millis();
  lcdshowstatus();
  leevaloresOW();
  for (byte i=0;i<1;i++) leevaloresDHT(i);
  procesaconsignas();
  if (WiFi.isConnected()) {
    if (conf.modomyjson == 1) { putmyjson(); }
    if (conf.mododweet == 1) { postdweet(mac); }
    if (conf.iottweetenable == 1) { postIoTweet(); }
    actualizaremotos();
    if (conf.mqttenable) 
      {  
      if (!PSclient.connected())  { 
        if (mqttreconnect()) {  
          mqttsubscribevalues();  }   }
      if ( PSclient.connected())  {
        mqttpublishvalues();  }  
      }
    }
  if ((millis()-tini)>5000) {printhora(); Serial.print(F(" 5 SEG:")); Serial.println(millis()-tini);}
  mact10 = millis();
}

void task60()     // 60 segundos
{
  tini = millis();
  memset(bevenENABLE, sizeof(bevenENABLE),0);
  procesaSemanal();
  procesaFechas();
  if ((millis() - tini) > 5000) { Serial.print(60); Serial.print(F(" SEG:")); Serial.println(millis() - tini); }
  mact60 = millis();
}

void task3600()         // 3600 segundos=1 hora
{
  tini = millis();
//  if (WiFi.isConnected()) {
//    timeClient.setTimeOffset(7200);
//    if (timeClient.update()==1) { countfaulttime=0; setTime(timeClient.getEpochTime());  }
//    checkMyIP();
//    checkForUpdates();
//    }
  if (millis()-tini>1000) { Serial.print(3600); Serial.print(F(" seg.:")); Serial.println(millis()-tini); }
  mact3600 = millis();
}

void modonormal()   // modo general
  {
  }

void loop(void) {
  if (conf.modohp!=1) 
    {
    tini=millis();
    if (Serial.available()) { char tChar = Serial.read(); if ((tChar=='\n') || (tChar=='\r')) { execcom(); sinput="";  } else { sinput=sinput+tChar;  } }
    handleRF();
    if (conf.ftpenable) ftpSrv.handleFTP();          
    server.handleClient();
    PSclient.loop(); 
    leevaloresDIG();
    //  analog0.update();
    //  analog1.update();
    //////////////////////////////////////////////////////////////////////////////////////////
    if ((millis() > (mact1 + 1000))) { task1(); }                     // tareas que se hacen cada segundo
    if ((millis() > (mact10 + (conf.peractrem * 1000)))) { taskvar(); }  // tareas que se hacen cada "peractrem" segundos
    if ((millis() > (mact60 + 60000))) { task60; }   // tareas que se hacen cada 60 segundos:1 minuto
    if ((millis() > (mact3600 + 3600000))) { task3600(); }   // tareas que se hacen cada 3600 segundos:1 hora
    if ((millis() > (mact86400 + 86400000)))    // tareas que se hacen cada 86400 segundos: 1 día
      {
      tini = millis();
      if (WiFi.isConnected()) { if (conf.iftttenable) ifttttrigger(conucochar, conf.iftttkey, conf.aliasdevice, "MyIP", conf.myippub); }
          if (millis()-tini>1000) {Serial.print(F("1 día.:")); Serial.println(millis()-tini);}
      mact86400 = millis();
      }
    }
  else if (conf.modohp==1) 
    {
    tini=millis();
    if (Serial.available()) { char tChar = Serial.read(); if ((tChar=='\n') || (tChar=='\r')) { execcom(); sinput="";  } else { sinput=sinput+tChar;  } }
    if (conf.ftpenable) ftpSrv.handleFTP();          
    server.handleClient();
    leevaloresDIG();
    if ((millis() > (mact1 + 1000))) { task1hp();   }      // tareas que se hacen cada segundo
    if ((millis() > (mact10 + 10000))) { task10hp(); }  // tareas que se hacen cada 10 segundos
    }
}

