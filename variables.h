
///////////////////////////////////////////////////////////////////////////////
typedef struct {byte pro[6]; unsigned long code[6]; int len[6];} rftype;   // 42 bytes
typedef struct {byte proon[18]; unsigned long codeon[18]; int lenon[18]; byte prooff[18]; unsigned long codeoff[18]; int lenoff[18];} code433type;   // 252 bytes
typedef struct {int devori; int actualizaut; float s[3]; float a1; char ua1[4]; int di[2],ds[2]; 
                long tdi[2],tdo[2]; char mac[13]; char idmyj[10]; float dhtdata[4][2]; } conucodata;

  typedef struct {    // datos configuración
                rftype rfkeys;
                code433type code433;
                char watermark[7]="conuco";        // código de verificación conuco
                byte iddevice=150;                // número dispositivo por defecto
                char aliasdevice[20]="NUEVO";     // 20 bytes, descripción del dispositivo
                byte bestado=0;                   // 1 bytes, estado de salidas digitales en el arranque
                byte valinic[maxSD]={2,2,2,2,2,2,2,2};  // 8x1, 8 bytes, valor inicial de las salidas digitales
                byte showN=0;                     // 1 byte, indica si se muestra el número de pin en la lista de señales
                unsigned int peractpan=15;        // 2 período de actualización automática página paneles
                byte prectemp=12;                 // precisión de la lectura de sondas DS18B20
                byte tipoED[maxED]={0,0,0,0};     // 4x1, 4 bytes, tipo de la entrada digital: 0=ON/OFF, 1=OFF/ON, 2=DHT11,3=DHT21,4=DHT22,5=RS485 RX/TX, ...
                byte bPRGeve[maxPrg][2];          // 16 bytes, para guardar 2x8 bits de asociación PRG-PRGeve
                byte usepassDev=0;                // 1 byte, 0 no usar password,  1 usar password
                char userDev[20]="admin";         // 20 bytes, usuario device
                char passDev[20]="admin";         // 20 bytes, password device
                byte modo45=0;                    // modo pines 4 y 5. NO USADO
                byte iottweetenable=0;            // enable/disable iottweet
                byte bprgval[1]={0};              // 1 byte, valor a poner en cada programación, on/off
                float factorA[maxEA]={1.0,1.0};   // 2x4 factor conversión analógicas locales
                float offsetA[maxEA]={0.0,0.0};   // 2x4 offset conversión analógicas locales
                char unitpinA[maxEA][4]={"",""};  // 16 bytes, unidades entrada analógica
                byte bsumatA[maxEA]={0,0};        // 4 byte, mostrar sumaA
                unsigned long tempdefact[maxSD]={0,0,0,0,0,0,0,0};// tiempos de activación por defecto. Si 0 es indefinido
                unsigned long tempdefdes[maxSD]={0,0,0,0,0,0,0,0};// tiempos de desactivación por defecto. Si 0 es indefinido
                byte staticIP=1;                  // 1 byte, IP estática Sí/No
                int TempDesactPrg=600;            // 2 bytes, tiempo desactivacion programacion en segundos, se compara con countfaulttime
                unsigned long contadores[maxED]={0,0,0,0};  // 16 bytes, número de veces encendido/apagado de entradas digitales
                byte actPrg[maxPrg]={0,0};        // 2 bytes, programas activos: 0/1
                int webPort=portdefault;          // 2 bytes, puerto servidor web
                byte LIBRES1[10][5];              // 50 bytes, LIBRES
                /********** variables wifi *************/
                byte wifimode=1;                  // 1 byte, 0:STA, 1: AP (default), 2: AP+STA
                char ssidSTA[20]="SSID_AP";       // 20 bytes, SSID en modo AP
                char passSTA[20]="PASS_AP";       // 20 bytes, Password en modo AP
                char ssidAP[20]="CONUCO_150";     // 20 bytes, SSID en modo STA
                char passAP[20]="12341234";       // 20 bytes, Password en modo STA
                byte pinremote[maxsalrem];        // 32 bytes, pin de cada salida remota
                byte idsalremote[maxsalrem];      // 32 bytes, id de dispositivos de cada salida remota
                
                byte bPRGsem[maxPrg][1];          // 8 bytes, para guardar 8x4 bits de asociación PRG-PRGsem
                byte prgsal[maxPrgSem];           // 8 bytes, salida a actuar en cada programación
                byte prgdia[maxPrgSem][1];        // 8 bytes, días de la semana, bits 0 a 6
                byte prghor[maxPrgSem]={0,0,0,0}; // 4 bytes, hora
                byte prgmin[maxPrgSem]={0,0,0,0}; // 4 bytes, minuto
                byte bshowEsc[1]={0};             // 1 byte, por bits, uno para escena
                byte bescena[maxEsc][5];          // 2 x 5 = 10 bytes, definición de escenas, conjuntamente con bescenaact
                byte bescenaact[maxEsc][5];       // 2 x 5 = 10 bytes, activación de escenas  (valor >0, ni ON ni OFF), conjuntamente con bescena
                byte bactfec[1]={0};              // 1 byte, por bits, uno por programa
                byte fecsal[maxPrgFec]={0,0,0,0}; // 4 bytes, salida a actuar en cada programación por fechas
                byte mqttsalenable[4]={0};        // publicar mqtt para cada señal.
                byte fecmes[maxPrgFec]={0,0,0,0}; // 4 bytes, mes
                byte fecdia[maxPrgFec]={0,0,0,0}; // 4 bytes, día del mes
                byte fechor[maxPrgFec]={0,0,0,0}; // 4 bytes, hora
                byte fecmin[maxPrgFec]={0,0,0,0}; // 4 bytes, minuto
                byte bfecval[1]={0};              // 1 byte, valor a poner en cada programación, on/off
                byte bconacttipo[1]={0};          // 1 byte, tipo de señal activadora en prg condición: local/remota
                byte condact[nEVE]={0,0,0,0,0,0,0,0};   // 8 bytes, 1 por cada condición, señal que activa la condición
                byte bconactmode[1]={0};                // 1 byte, tipo de activadora en prg condición: cambio/estado
                byte condvalD[nEVE]={0,0,0,0,0,0,0,0};  // 8 bytes, valor de activación del condición para digitales
                byte evencomp[nEVE]={0,0,0,0,0,0,0,0};  // 8 bytes, comparador: =, <>, >=, ....
                float evenvalA[nEVE]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};  // 32 8x4, valor de activación del condición para analógicas
                float evenhis[nEVE]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};   // 32 8x4, valor de histéresis de activación del condición
                byte bconsaltipo[1]={0};               // 1 byte, tipo de salida en prg condición: local/remota
                byte evensal[nEVE]={0,0,0,0,0,0,0,0};  // 8 bytes define la señal sobre la que se actua
                byte bevenniv[8]={0,0,0,0,0,0,0,0};    // 8 bytes, define nivel a activar.
                char EEmac[6][3];                 // 18 bytes, MAC
                IPAddress EEip={192,168,1,150};   // 4 bytes, dirección IP
                IPAddress EEgw={192,168,1,1};     // 4 bytes, puerta de enlace
                IPAddress EEmask={255,255,255,0}; // 4 bytes, máscara de subred
                IPAddress EEdns={8,8,8,8};        // 4 bytes, servidor DNS primario
                IPAddress EEdns2={8,8,4,4};       // 4 bytes, servidor DNS secundario
                byte ipremote[maxdevrem]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};    // 16 bytes, último byte IP de cada dispositivo remoto
                byte bshowpanel[2]={1,0};         // 2 bytes, paneles activos
                byte idremote[maxdevrem]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};    // 16 bytes, ID de cada dispositivo remoto
                byte senalrem[maxsalrem];         // 32 bytes, pin de cada señal remota: 0,1,2 Sonda, 3 Analógica, 4,5 Ent. digital, 6,7 Sal. digital
                char iottweetkey[15]="";          // 15 bytes, IoTtweet account key
                unsigned long timeoutrem=500;     // 4 bytes, timeout para conexión con remotos
                unsigned long timeoutNTP=1000;    // 4 bytes, timeout para conexión con servicios de red
                char iottweetuser[10]="";         // 10 bytes, IoTtweet account user ID
                int peractrem=10;                 // 2 bytes, período de actualización automática a dispositivo maestro
                byte tipoi2cmbrem[maxsalrem];     // 32 bytes, tipo de sensor de cada señal remota, I2C: 1:BMP085...
                byte iftttenable=0;               // 1 byte, ifttt desactivado
                char iftttkey[30]="";             // 30 bytes, ifttt key
                byte iftttpinED[maxED]={0,0};     // 2 bytes, enviar ifttt entradas digitales, byte 1 para ON, byte 2 para OFF
                byte iftttpinSD[maxSD]={0,0};     // 2 bytes, enviar ifttt salidas digitales, byte 1 para ON, byte 2 para OFF
                byte mododweet=0;                 // 1 byte, dweet.io desactivado
                byte canalAP=3;                   // 1 byte, canal ESP en modo AP
                byte modomyjson=0;
                byte idmyjsonST=0;                // 1 byte, indica si se ha obtenido y almacenado ya la ID de myjson
                char idmyjson[10]="";             // 10 bytes, ID myjson
                byte modoterm=0;                  // 1 byte
                float latitud=0.0;
                float longitud=0.0;
                char myippub[16]="";              // 16 bytes, dirección IP pública
                byte actualizaut=0; 
                char hostmyip[30]="icanhazip.com";// 30 bytes, URL del servidor de IP pública
                char fwUrlBase[80]="http://conucoserver.000webhostapp.com/";
                byte bPRGwebcall[1]={0};          // 1 byte, desactiva web call
                byte netseg=1;                    // 1 byte, segmento de red=EEip[2]
                float setpoint[maxTemp]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};  // setpoint temperaturas
                byte salsetpoint[maxTemp]={0,0,0,0,0,0,0,0};      // salida asociada al setpoint (0,1 salidas locales; 2-17 salidas remotas)
                byte accsetpoint[maxTemp]={2,2,2,2,2,2,2,2};      // acción asociada al setpoint (1=OFF,2=ON,0=ninguna)
                byte MbC8[2]={0};                 // byte 1 para SD, byte 2 para ED
                byte ftpenable=1;                 // 0=disnable, 1=enable
                byte lang=0;                      // 0=español, 1=inglés
                byte mqttenable=0;                // desactiva MQTT
                char mqttserver[40]="";           // MQTT broker
                char mqttpath[6][10]={"","","","","",""};             // MQTT path
                char instname[10]="INSTAL";       // nombre de la instalación
                unsigned int tempmqtt[22]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  // período de envío mqtt para cada señal
                                          // 8 temp, 2 anal, 4 ent. dig, 8 sal. dig.    // NO USADO
                byte modohp=0;  // modo bomba de calor = 1;
                byte ngpio[30]={25,25,25,25,25,25,25,25,27,4,35,34,39,36,17,23,22,21,19,5,18,16,25,26,0,0,0,0,0,0};  // pin para cada señal 8x1-wire,2xEA,4xDI,8xDO, 2DHT, 6 libres)
                byte tiporemote[maxdevrem]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};    // 16 bytes, tipo de cada dispositivo remoto. 0:Conuco8266, 1:conuco32
                byte bshowbypanel[maxpaneles][7]; // 70 bytes, tabla para asignar señales a paneles
               } conftype;
    conftype conf;     
    byte *buffconf = (byte *) &conf; // acceder a conf como bytes

    byte edPin[maxED]={I0,I1,I2,I3};                // pines entradas digitales
    byte sdPin[maxSD]={O0,O1,O2,O3,O4,O5,O6,O7};    // pines salidas digitales/relés
    byte anaPin[maxEA]={ADC0,ADC1};                 // pines entradas analógicas
    byte i2cPin[2]={SDA,SCL};                       // pines I2C
    byte spiPin[4]={SPIMISO,SPIMOSI,SPICLK,SPICS};  // pines SPI
    byte txrxPin[2]={TX,RX};                        // pines serial port
    byte rfPin[2]={RX433,TX433};                    // pines RF 433
    byte adcPin[2]={ADC0,ADC1};                     // pines ADC
    byte dacPin[2]={DAC0,DAC1};                     // pines DAC
    byte dhtPin[2]={DHT0,DHT1};                     // pines DHT
    byte owPin=W0;                                  // pin para DS18B20
    const byte listgpio[27]={1,2,3,4,5,12,13,14,15,16,17,18,19,21,22,23,25,26,27,32,33,34,35,36,37,38,39};
    const char idpin8266[15][4]={"t0","t1","t2","a0","e0","e1","s0","s1","id","ip","ipp","c0","c1","c2","all"}; // hasta el 8 son pines.
    const char idpin[34][4]={"t0","t1","t2","t3","t4","t5","t6","t7","a0","a1","e0","e1","e2","e3","s0","s1","s2","s3","s4","s5","s6","s7","id","ip","ipp",
                             "c0","c1","c2","c3","c4","c5","c6","c7","all"};
        // hasta el 22 son pines

//////  tratamiento de bits /////////////////////
const byte tab[8] = {1,2,4,8,16,32,64,128}; // 8

/********* IMPORTANTE  *****************/
const byte valorpin[2] ={0,1};    // directo 0=LOW,  1=HIGH    

////UPDATER
int verserver=0; 
int versinsttemp=0;
byte actualizauttemp=0;
const char* update_username ="admin";
const char* update_password ="admin";
char fwUrlBasetemp[80]="";
////UPDATER END

String msg;                     // String donde se construye la respuesta HTML qu e se envía al cliente
char buff[20];                  // 20 bytes, auxiliar
char auxchar[130];              // 130 bytes, auxiliar 
char auxdesc[60];               // 60 bytes, auxiliar para lectura de descriptores de archivos
//byte addr[maxTemp][8];          // 3x8, 24 bytes identificador de cada sonda DS18B20 (64)
int peractpantemp=10;           // 2 período de actualización automática página panel
int peractremtemp=10;           // 2 período de actualización automática a nodo raíz
byte bsumatAtemp[maxEA]={0};   // 1 byte,  mostrar sumaA temp
int valoresTemp[maxTemp]={0,0,0,0,0,0,0,0}; // 8x2, 16 bytes guarda los valores de las sondas dividido por 100
byte nTemp=0;                  // número sondas detectadas en cada puerto 1-wire
uint8_t addr1Wire[maxTemp][8];
unsigned long mact1,mact2,mact10,mact60,mact3600,mact86400; 
unsigned long tempact[maxSD];   // 8x4, 32 bytes, tiempos desde activación. Al llegar a tempdef se desactiva la salida.
unsigned long tempdes[maxSD];   // 8x4, 32 bytes, tiempos desde desactivación. Al llegar a tempdef se activa la salida.
byte tipoEDtemp[maxED]={0,0,0,0};   // 4x1, 4 bytes, tipo de la entrada digital: 0=ON/OFF, 1=OFF/ON, 2=DHT11,3=DHT21,4=DHT22,5=RS485 RX/TX, ...
int nAP=0;                      // 2 bytes, redes encontradas con scanAP
int nAPact=0;                   // 2 bytes, redes actual
int countfaulttime=29999;       // veces que ha fallado la sincronización
int param_number=0;             // variables auxiliares para parámetros en POST
int indice=0;                   // variables auxiliares para parámetros en POST
int resto=0;                    // variables auxiliares para parámetros en POST
int mival=0;                    // variables auxiliares para parámetros en POST
int mp=1;                       // variables auxiliares para parámetros en POST
int mpi=0;                      // variables auxiliares para parámetros en POST
boolean colorea;                // variables auxiliares para parámetros en POST
long timerem[maxdevrem];        // tiempo en minutos desde última conexión con remoto
boolean actirem[maxdevrem];     // 16 bytes, activo remoto
long contaremote[maxsalrem];    // 32x4, 128 bytes, contadores o tiempo de encendido o apagado de señales remotas, en segundos
boolean actisenal[maxsalrem];   // 32 bytes, señales remotas activas
char unitpinAtemp[4];           // 4 char, unidades entradas analógicas
byte evenTemp[nEVE];            // 8 define la señal sobre la que se actua, variable temporal
byte bconactcumple[4];          // valor de cumplimiento actual de la condición
// variables para programación SEMANAL
int TempDesactPrgtemp=600;      // 2 bytes, tiempo desactivacion programacion en segundos, se compara con countfaulttime
int mbtemp[16];                 // temperaturas remotos modbus
int mbcons[16];                 // consignas remotos modbus
byte mbstatus[2];               // estado relés remotos modbus (1 bit cada uno);
byte bstatremote[4];            // 4 bytes, estado de cada posible salida remota
byte tipoedremote[32];          // 32 bytes, tipo de cada posible entrada digital remota, 0=ON/OFF, 1=DHT
float sondaremote[maxsalrem];   // 128 bytes, valores de sondas remotas

char mac[14]="";                // MAC del dispositivo

byte bevenENABLE[2][8];         // 2x8, 16 bytes, define si la condición ha activado ya algo
char host[16]="";
char hostraiz[16]="192.168.";
byte NumOri=0;
boolean statusChange=false;
byte ListOri[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float factorAtemp[maxEA]={1.0,1.0}; // 1x4 factor conversión analógicas locales temp
float offsetAtemp[maxEA]={0.0,0.0}; // 1x4 offset conversión analógicas locales temp

byte MbC8ant[2]={0};             // estado anterior de SD y ED: 0:SD0, 1:SD1, 2:ED0, 3:ED1
int MbR[10];                     // 0-7 Temperaturas locales, 8-9 analógica local
int MbRant[10];                  // 0-7 Temperaturas locales, 8-9 analógica local, valores anteriore
byte iftttchange[2]={0};         // 0-7: salidas digitales,  8-11: entradas digitales
char idmyjsontemp[10]="";
boolean onescenaact=false;
byte secori=0;
int tempbt2=0;
float latitudtemp, longitudtemp;
char conucochar[7]="conuco";

int moddevicetemp=0;     
byte wifimodetemp=2;
byte iddevicetemp=0;     
char aliasdevicetemp[20]="";
char ssidSTAtemp[20]="";
char passSTAtemp[20]="";
byte iftttenabletemp=0;  
char iftttkeytemp[30]="";
byte modomyjsontemp=0;
byte mododweettemp=0;
byte valinictemp[2]={0,0};
unsigned long tempdefacttemp[2];    // tiempos de activación por defecto. Si 0 es indefinido
unsigned long tempdefdestemp[2];    // tiempos de desactivación por defecto. Si 0 es indefinido
byte iftttpinEDtemp[2]={0};         // 2 bytes, enviar ifttt entradas digitales,byte 1 para ON, byte 2 para OFF
byte iftttpinSDtemp[2]={0};         // 2 bytes, enviar ifttt salidas digitales, byte 1 para ON, byte 2 para OFF
byte posactio=0;
byte posactsem=0;
byte posactrem=0;
byte posactsalrem=0;
byte posacteve=0;
byte posactfec=0;
byte posactesc=0;
char iottweetusertemp[10];          //IoTtweet account user ID (6 digits, included zero pre-fix)
char iottweetkeytemp[15];           //IoTtweet account user ID (6 digits, included zero pre-fix)
byte iottweetenabletemp=0;
long modbusbaud=19200;
String private_tweet="Mi Conuco";                  //Your private tweet meassage to dashboard
String public_tweet="Conuco";         //Your public tweet message to dashboard
byte lastpro=0;
long lastcode=0;
int lastlen=0;
byte paract=0;
float dhtdata[4][2];
byte panelact=0;
//byte priremio=0;
byte hacerresetrem=0;
long lastReconnectAttempt=0;
boolean pendsave = false;
boolean bmp085enabled=false;
conucodata datosremoto;

char admin[]="admin";

boolean filesok=false;
char fileconf[]="/conf.txt";
char filezonas[]="/zonas.txt";
char filedevrem[]="/devrem.txt";
char filesalrem[]="/salrem.txt";
char filewebcall[]="/webcall.txt";
char fileurlwebcall[]="/urlwebcall.txt";
char filedescprg[]="/descprg.txt";
char filedescesc[]="/descesc.txt";
char filemacdevrem[]="/macdevrem.txt";
char fileidmyjsonrem[]="/idmyjsonrem.txt";
char fileunitsalrem[]="/unitsalrem.txt";
char filedesclocal[]="/desclocal.txt";
char filedesctemp[]="/desctemp.txt";
char filei2ctypes[]="/i2ctypes.txt";
char filecommon[]="/common.txt";
char filespanish[]="/spanish.txt";
char fileenglish[]="/english.txt";
char filelog[]="/log.txt";
char filedash[]="/dash.txt";

int testvalue=0;
unsigned long tini=0;

////////////////////////////////////////
