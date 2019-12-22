

void initTFT()
{
  digitalWrite(TFT_RST,0); delay(50); digitalWrite(TFT_RST,1);
  tft.init(); tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
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

void drawED()   // entradas digitales
{
  for (byte i=0;i<4;i++)
    {
    btED[i].initButtonUL(&tft,0,50*i,158,40,2,getbit8(conf.MbC8,i+8)==1?TFT_YELLOW:TFT_WHITE,TFT_BLACK,readdescr(filedesclocal,i+8,20),2);
    btED[i].drawButton();
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
}

void drawSET()     // barra setup
{
    btSET[0].initButtonUL(&tft,80*0+2,25,75,40,2,TFT_WHITE,TFT_BLACK,"RST",2);  btSET[0].drawButton();
}

void drawTFT()
{
  if (tftpage==0) { drawSD(); }
  else if (tftpage==1) { drawED(); }
  else if (tftpage==2) { drawTE(); }
  else if (tftpage==3) { drawAN(); }
  else if (tftpage==4) { drawIP(); }
  else if (tftpage==5) { drawSET(); }
  drawST();
}

void handletfttouch()
{
  uint16_t x, y;
  if (tft.getTouch(&x, &y))
    {
    Serial.print(x); Serial.print("-"); Serial.print(y);
    if (tft.getRotation()==3) { x=tft.width()-x; y=tft.height()-y;}
    for (byte i=0;i<4;i++)    // cambio de página
      {
      if (btST[i].contains(x,y))  // botones página atrás/adelante
        {
        Serial.print("  btST:"); Serial.print(i);
        if (i==0) if (tftpage>0) { tftpage--; } else { tftpage=5; }
        if (i==3) if (tftpage<5) { tftpage++; } else { tftpage=0; }
        tft.fillScreen(TFT_BLACK); drawTFT(); 
        }
      }
    for (byte i=0;i<maxSD;i++)  // botones salidas digitales 
      {
      if (btSD[i].contains(x,y)) 
        {
        Serial.print("  btSD:"); Serial.print(i);
        if ((i>=0) && (i<=maxSD)) { pinVAL(i, getbit8(conf.MbC8,i)==0?1:0,conf.iddevice); }
        drawTFT(); 
        }
      }
    for (byte i=0;i<4;i++)  // botones salidas digitales
      {
      if (btSET[i].contains(x,y))  { if (i==0) { ESP.restart(); }; }
      }
    Serial.println();
    }
}

