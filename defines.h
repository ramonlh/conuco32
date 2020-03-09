
  #define modelo 32
  #define portdefault 88
  #define ROMsize 4096
  #define maxerrorrem 5
  #define SLAVE 0
  #define MASTER 1
  #define maxgpio 26
  #define maxgpiovar 10
  #define maxED 4         // número entradas digitales
  #define maxSD 8        // número salidas digitales + reléss
  #define maxEA 2         // número ADC
  #define maxDAC 2        // número DAC
  #define maxDHT 10       // tantas como gpiovar  
  #define maxTemp 8       // número máximo de sondas ds18B20
  #define maxWire 2       // número de puertos 1 wire
  #define maxdevrem 16    // número de dispositivos remotos
  #define maxsalrem 32    // número de salidas remotas
  #define maxPrg 8        // número de programas
  #define maxPrgSem 8     // número de programas semanales
  #define maxPrgFec 4     // número de programas fechas
  #define maxEsc 8        // número de escenas
  #define maxwebcalls 4   // número máximo de web calls
  #define maxparam 14     // número máximo parámetros LCD
  #define maxpaneles 10   // número máximo de paneles
  #define maxsensortype 30 
  #define maxtftpages 6
  #define maxAP 9
  
  // 
  #define I0 36    // OK    // Inputs
  #define I1 39    // OK  
  #define I2 34    // OK  
  #define I3 35    // OK  

  #define O0 17    // OK  Outputs Relé 1
  #define O1 23    // OK          Relé 2     
  #define O2 25    // OK          Relé 3 a partir de PCB v4          
  #define O3 27    // OK          Relé 4 a partir de PCB v4
  #define O4 19    // OK    
  #define O5 5     // OK          
  #define O6 18    // OK            
  #define O7 16    // OK          Relé 8
  
  #define W0 26    // 1 wire port 

//  #define TX 1   // UART1 
//  #define RX 3
  #define RXD2 22  // UART2
  #define TXD2 32
  #define RX433 4 
  #define TX433 2     

////////////////////////////////
#define nEVE 8          // número de eventos
#define despIFTTT 252   // valor para disparar IFTTT, 252
#define timerf 100      // milisegundos mínimo para órdenes RF
////////////////////////////////////////////////////////////////////////////////////
#define BMP085_ADDRESS 0x77  // I2C address of BMP085
#define i2ctimeout 200

//////////////////////////////////////////////////////////////////////
////// textos, deben coincidir con los textos del fichero spanish.txt/english.txt/otros idiomas
#define Act 1
#define activadora 2
#define activo 3
#define aut 4
#define periodoact255 5
#define actualizar 6
#define ana 7
#define analogica 8
#define ano 9
#define asociara 10
#define autenticacion 11
#define canal 12
#define compa 13
#define condiciones 14
#define tconectado 15
#define conectando 16
#define conectar 17
#define configuracion 18
#define confcontrasena 19
#define consigna 20
#define contrasena 21
#define de 22
#define des 23
#define descripcion 24
#define dia 25
#define DIRIP 26
#define disp 27
#define dispositivo 28
#define ejecutar 29
#define ent 30
#define entanalog 31
#define entradasdig 32
#define entrada 33      // no usada
#define noconf 34
#define escena 35
#define escenas 36
#define statust 37
#define fabrica 38
#define fecha 39
#define files 40
#define guardar 41
#define hora 42
#define inicial 43
#define staticip 44
#define ippublica 45
#define lat 46
#define tlon 47
#define latitudt 48
#define longitudt 49
#define mandorf 50
#define mes 51
#define Modo 52
#define mostrarpines 53
#define NO 54
//#define nada 55
#define nombre 56
#define notificar 57      // no usada
#define notifttt 58
#define NUEVO 59
#define nuevoremoto 60
#define pines 61
#define preciokwh 62
#define programa 63
#define programas 64
#define tred 65
#define servred 66
#define reiniciando 67
#define rele 68     // no usada
#define tremoto 69
#define remotos 70
#define periodoactrem 71
//#define tresetfab 72
#define tresetfiles 73
#define saldig 74
#define salida 75
#define explorar 76
#define seguridad 77
#define semanal 78
#define senal 79
#define ippubserver 80
#define SI 81
#define sistema 82
#define sonda 83
#define sondastemp 84
#define SR 85
#define temperatura 86    // no usada
#define termostato 87
#define tdp 88
#define ttimeoutrem 89    // no usada
#define ttipo 90
//#define ultimovalor 91
#define units 92
#define usuario 93
#define tvalor 94
#define versiont 95
#define versionact 96
#define versioncheckfail 97
#define webcalls 98
#define instalada 99
#define actual 100        // no usada
#define wifimodet 101
#define zona 102
#define zonas 103
#define ftpserver 104
#define instalacion 105
#define hist 106
#define pietiporem 107
//#define nohacernada 108
#define faltafichero 109
#define useftp 110
#define guardarexportar 111  
#define idioma 112  
#define bombacalor 113  

//////////////////////////////////////////////////////////////////////
////// textos, deben coincidir con los textos del fichero common.txt
#define dbm 2
#define Time 3
#define Chipid 4
#define ChipFlashSize 5
#define Chipspeed 6
#define sdkversion 7
#define vdd33 8
#define adc_read 9
#define boot_version 10
#define boot_mode 11
#define userbin_addr 12
#define cpu_freq 13
#define flash_get_id 14
#define opmode 15
#define opmode_default 16
#define connect_status 17
#define get_current_ap_id 18
#define auto_connect 19
#define dhcpc_status 20
#define hostnamet 21
#define station_num 22
#define dhcps_status 23
#define phy_mode 24
#define sleep_type 25
#define broadcast_if 26
#define user_limit_rate_mask 27
#define channelt 28
#define free_heap_size 29
#define rtc_time 30
#define BMP085notfound 31
#define sensori2c 32
#define mqtt 33
#define tpath 34
// Roomba
#define START 35
#define BAUD 36
#define CONTROL 37
#define SAFE 38
#define FULL 39
#define POWER 40
#define SPOT 41
#define CLEAN 42
#define MAX 43
#define DRIVE 44
#define MOTORS 45
#define LEDS 46
#define SONG 47
#define PLAY 48
#define SENSORS 49
#define DOCK 50
// direcciones  51-66
#define xmlns 51             
#define myjsoncom 52
#define iottweetcom 53
#define gmaps 54
#define urliotwweet 55
#define icanhazip 56
#define urlapimyjson 57
//#define urlNTPserverpool 58
#define iftttcom 59
#define makeriftttcom 60
#define urldweet 61
#define getdweett 62
#define getlastdweett 63
#define dweetfor 64
#define dweetio 65
#define inobin 66
#define tparasite 67 
#define tpower 68
#define minuto 69
#define tport 70
#define tfile 71
#define updatet 72 
#define device 73
#define chipsize 74
#define chipspeed 75
#define dns 76
#define tmask 77
#define modet 78
#define gateway 79
#define thttp 80
#define thttps 81
#define alias 82
//#define t12341234 83
//#define i2c 84
//#define intro 85
//#define esc 86
#define up 87
#define down 88
#define left 89
#define rigth 90
//#define ups 91
//#define downs 92
//#define lefts 93
//#define rigths 94
#define rf 95
//#define modbust 96
#define t32p 97
#define senales 98 
#define iottweett 99
#define modomyjsont 100
#define api 101
//#define diginput 102
#define tadmin 103
#define tspiffs 104
#define pretty 105
#define watermarkt 106 
#define webcall 107
#define notdefined 108
#define hidden 109
#define thost 110
#define tIP 111
#define runningt 112
#define twifi 113
#define ttimeoutNTP 114
#define smtpPER 115
#define smtpSVR 116
#define smtpPORT 117
#define smtpUSER 118
#define smtpPASS 119
#define smtpREMI 120
#define smtpDEST1 121
#define tpinvalr 122
#define unit 123
#define si 124
#define no 125
#define tdefact 126
#define tdefdes 127
#define ron 128
#define roff 129
#define panel 130
#define dig 131
#define digital 132 
#define addrt 133
#define apssid 134
#define appass 135
#define defaultt 136
#define devremotot 137
#define disabled 138
#define dweet 139
#define terror 140
#define esp8266 141
#define routerssid 142
#define routerpass 143
#define systemt 144
//#define submit 145
#define dweetname 146
#define trem 147
#define salremotas 148
//#define treset 149
//#define tresetwifi 150 
//#define trestart 151
#define rfkey 152
//#define rfon 153
//#define rfoff 154
#define treqjson 155
#define i2cdevnotfound 156
#define unkerrorat 157
#define i2cnodevices 158
#define fontsize6 159
#define trigger 160
#define withkey 161
#define t301 162
#define t303 163
#define t404 164
//#define applicationjson 165
#define applicationoctet 166
#define bins  167
#define body_i  168
#define body_f 169
#define cachecontrol 170
#define checkbox 171
#define center_i 172
#define center_f 173
#define tclass 174
#define tconnection 175 
//#define closet 176
//#define contenttype 177
#define contentdisposition 178
#define conuco 179
#define CONUCO 180
#define tdata 181
//#define dataType 182 
#define espsessionid 183 
#define tform 184
#define form_f 185
#define handleclientt 186
//#define thead 187
//#define thtml 188
#define HTTP11 189

#define newpage 190
#define onclickclose 191
#define DISCONNECTYES 192
//#define textplain 193
#define lengt 194
#define location 195
#define logt 196
#define idmyjsont 197
#define namet 198
#define nocache 199
#define optionvalue 200 
#define option_f 201
#define pagenotfound 202 
#define tpassword 203
#define pre_i 204
#define pre_f 205
//#define tPOST 206
#define PRG 207
//#define PUT 208
#define seeother 209
#define select_f 210
#define Select_name 211
#define tserver 212
#define setcookie 213
//#define table 214
#define max_length 215
#define Form_post 216
//#define attachfilename 217
#define head_f 218
#define form_action 219
#define SMALL 220
#define htmlRefresh_i 221
#define fontsize_i 222
#define font_f 223
#define color000000 224
#define colorffffcc 225
#define invis 226
#define ifttt 227
#define tinput 228
#define Key 229
#define tver 230
#define vers 231
#define web 232
#define tid 233
#define tdcolspan_i 234
#define resetcontp 235 
#define title 236
//#define toff 237
//#define tvalue 238
#define actwc 239
#define ttext 240
//#define ap 241
//#define apsta 242
//#define sta 243
#define factor 244
#define toffset 245
//#define checked 246
//#define href_i 247
//#define selected 248
//#define iftttkeyt 249
#define tssid 250
#define tpass 251
#define thr 252
#define td_if 253
//#define dhtt 254
//#define ONOFF 255
#define urltext 256
#define Firmware 256
#define MAC 258
#define BMP085OK 259
#define dashmainTextSize 260
#define dashpostfix 261
#define dashprefix 262
#define dashtextcolor 263
#define dashenableIntermediateState 264
#define dashenablePub 265
#define dashenteredIntermediateStateAt 266
#define dashintermediateStateTimeout 267
#define dashjsOnReceive 268
#define dashjsonPath 269
#define dashlastPayload 270
#define dashqos 271
#define dashretained 272
#define dashtopic 273
#define dashtopicPub 274
#define dashupdateLastPayloadOnPub 275
#define dashid 276
#define dashjsBlinkExpression 277
#define dashjsOnDisplay 278
#define dashjsOnTap 279
#define dashlastActivity 280
#define dashlongId 281
#define dashname 282
#define dashtype 283
#define tcelsius 284
#define medium 285
#define ttrue 286
#define tfalse 287
#define ic_radio_button_unchecked 288
#define ic_radio_button_checked 289
#define dashoffcolor 290 
#define dashoncolor 291 
#define dashpayloadoff 292 
#define dashpayloadon 293 
#define ic_settings_poweroff 294 
#define ic_settings_poweron 295 
#define eventdatalast01 296
#define apppublish 297
#define ifeventdata 298
#define evendatalast 299
#define dashiconoff 300
#define dashiconon 301
#define gpio 302
//#define small 303
#define localip 304
#define publicip 305
#define maindevice 306
#define mqttdashtopic 307
#define tlink 308

