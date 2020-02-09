void clearTFT()
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void drawStarting()
  {
  clearTFT();
  tft.setTextSize(2);
  tft.drawString("Starting",0,0);
  tft.drawString("Vers.",0,25);
  tft.drawNumber(versinst,100,25);
  tft.drawString("Connecting WiFi",0,50);
  }

void initTFT()
{
  digitalWrite(TFT_RST,0); delay(50); digitalWrite(TFT_RST,1);
  tft.init(); tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  lasttouch=millis();
  tfton=true;
  drawStarting(); 
}

void drawTE()   // temperaturas
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK); tft.setTextSize(2);
  for (byte i=0;i<4;i++)
    {
    tft.setTextColor(TFT_WHITE, TFT_BLACK); tft.setTextSize(2);
    tft.drawString(readdescr(filedesclocal,i,20),0,50*i+15);
    dtostrf(MbR[i]*0.01,4,1,auxdesc);
    btTE[i].initButtonUL(&tft,100,50*i,58,40,2,TFT_WHITE,TFT_BLACK,auxdesc,2);
    btTE[i].drawButton();
    }
  for (byte i=4;i<maxTemp;i++)
    {
    tft.setTextColor(TFT_WHITE, TFT_BLACK); tft.setTextSize(2);
    tft.drawString(readdescr(filedesclocal,i,20),165,50*(i-4)+15);
    dtostrf(MbR[i]*0.01,4,1,auxdesc);
    btTE[i].initButtonUL(&tft,265,50*(i-4),58,40,2,TFT_WHITE,TFT_BLACK,auxdesc,2);
    btTE[i].drawButton();
    }
}

void drawSO()   // sondas y códigos
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK); tft.setTextSize(2);
  for (byte i=0;i<maxTemp;i++)
    {
    tft.setTextColor(TFT_WHITE, TFT_BLACK); tft.setTextSize(2);
    tft.drawString(letraS,0,25*i); tft.drawNumber(i, 15, 25*i);
    if (conf.nprobe[i]<nTemp) tft.drawNumber(conf.nprobe[i], 35,25*i);
    else tft.drawString("NA",35,25*i);
    for (byte j=0;j<8;j++) 
      {
      tft.drawHex(conf.probecode[i][j], 75+(j*30), 25*i);
      if (j<7) tft.drawString(":", 97+(j*30), 25*i);
      }
    }
}

void drawED()   // entradas digitales
{
  for (byte i=0;i<4;i++)
    {
    btED[i].initButtonUL(&tft,0,50*i,158,40,2,getbit8(conf.MbC8,i+8)==1?TFT_YELLOW:TFT_WHITE,TFT_BLACK,readdescr(filedesclocal,i+8,20),2);
    btED[i].drawButton();
    tft.setTextColor(TFT_WHITE, TFT_BLACK);  tft.setTextSize(2);
    tft.drawNumber(conf.contadores[i],180, 50*i+10); 
    }
}

void drawSD()   // salidas digitales
{
  for (byte i=0;i<4;i++)
    {
    btSD[i].initButtonUL(&tft,0,50*i,158,40,2,getbit8(conf.MbC8,i)==1?TFT_YELLOW:TFT_WHITE,TFT_BLACK,readdescr(filedesclocal,i+12,20),2);
    btSD[i].drawButton();
    }
  for (byte i=4;i<maxSD;i++)
    {
    btSD[i].initButtonUL(&tft,160,50*(i-4),158,40,2,getbit8(conf.MbC8,i)==1?TFT_YELLOW:TFT_WHITE,TFT_BLACK,readdescr(filedesclocal,i+12,20),2);
    btSD[i].drawButton();
    }
}

void drawAN()   // GPIOS variables
{
  for (byte i=0;i<maxDAC;i++)
    {
    btAN[i].initButtonUL(&tft,0,50*i,158,40,2,TFT_WHITE,TFT_BLACK,"GPIO XXX",2);
    btAN[i].drawButton();
    }
}

void drawIP()   // valores LAN
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  for (byte i=0;i<4;i++)
    {
    tft.drawString("IP",0,0); tft.drawNumber(conf.EEip[i], 50*i+70, 0); if (i<3) tft.drawString(".",50*i+105,0);
    tft.drawString("Mask",0,30); tft.drawNumber(conf.EEmask[i], 50*i+70, 30); if (i<3) tft.drawString(".",50*i+105,30);
    tft.drawString("GW",0,60); tft.drawNumber(conf.EEgw[i], 50*i+70, 60); if (i<3) tft.drawString(".",50*i+105,60);
    tft.drawString("DNS",0,90); tft.drawNumber(conf.EEdns[i], 50*i+70, 90); if (i<3) tft.drawString(".",50*i+105,90);
    tft.drawString(WiFi.SSID(),0,120);
    }
}

void drawST()     // barra navegación
{
    btST[0].initButtonUL(&tft,80*0+2,200,75,40,2,TFT_WHITE,TFT_BLACK,flecha[0],2);  btST[0].drawButton();
    btST[3].initButtonUL(&tft,80*3+2,200,75,40,2,TFT_WHITE,TFT_BLACK,flecha[3],2);  btST[3].drawButton();
    tft.setTextSize(2);
    tft.setTextColor(WiFi.isConnected()?TFT_GREEN:TFT_RED, TFT_BLACK);
    tft.drawString("===",110,220);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawNumber(tftpage,85,220);
    tft.drawNumber(hour(),150,220); tft.drawString(":",172,220);
    tft.drawNumber(minute(),180,220); tft.drawString(":",205,220);
    tft.drawNumber(second(),second()<10?228:215,220);  
}

void drawSET()     // barra setup
{
    btSET[0].initButtonUL(&tft,80*0+2,25,75,40,2,TFT_WHITE,TFT_BLACK,"RST",2);  btSET[0].drawButton();
}

void drawFT817()
{
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);  tft.setTextSize(5);
  tft.drawFloat(145.35512,5,5,5); 

  bt817[0].initButtonUL(&tft,0,200,60,40,2,TFT_YELLOW,TFT_BLACK,"ON",2);  bt817[0].drawButton();
  bt817[1].initButtonUL(&tft,60,200,60,40,2,TFT_YELLOW,TFT_BLACK,"OFF",2);  bt817[1].drawButton();
  
}

void drawTFT()
{
  if (conf.modobc==0)
    {
    if (tftpage==0) { drawSD(); }
    else if (tftpage==1) { drawED(); }
    else if (tftpage==2) { drawTE(); }
    else if (tftpage==3) { drawAN(); }
    else if (tftpage==4) { drawIP(); }
    else if (tftpage==5) { drawSET(); }
    else if (tftpage==6) { drawSO(); }
    drawST();
    }
  else if (conf.modobc==1)  // bombacalor
    {
    if (tftpage==0) { drawSD(); }
    else if (tftpage==1) { drawED(); }
    else if (tftpage==2) { drawTE(); }
    else if (tftpage==3) { drawAN(); }
    else if (tftpage==4) { drawIP(); }
    else if (tftpage==5) { drawSET(); }
    else if (tftpage==6) { drawSO(); }
    drawST();
    }
  else if (conf.modobc==2)    // ft817
    {
    drawFT817();
    }
}

