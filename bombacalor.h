boolean V4VON() { return digitalRead(sdPin[1])==1; }
boolean BCalON() { return digitalRead(sdPin[2])==1; }
boolean BCapON() { return digitalRead(sdPin[3])==1; }
boolean BACSON() { return digitalRead(sdPin[4])==1; }
boolean CompON() { return digitalRead(sdPin[5])==1; }
boolean AlarmON() { return digitalRead(sdPin[7])==1; }

void setV4VON() { if (V4VON()) return; pinVAL(1, 1, conf.iddevice);}
void setV4VOFF() { if (!V4VON()) return; pinVAL(1, 0, conf.iddevice);  }
void setBCalON() { if (BCalON()) return; pinVAL(2, 1, conf.iddevice);}
void setBCalOFF() { if (!BCalON()) return; pinVAL(2, 0, conf.iddevice);  }
void setBCapON() { if (BCapON()) return; pinVAL(3, 1, conf.iddevice);  }
void setBCapOFF() { if (!BCapON()) return; pinVAL(3, 0, conf.iddevice);  }
void setBACSON() { if (BACSON()) return; pinVAL(4, 1, conf.iddevice);  }
void setBACSOFF() { if (!BACSON()) return; pinVAL(4, 0, conf.iddevice);  }
void setComprON() { if (CompON()) return; pinVAL(5, 1, conf.iddevice);  }
void setComprOFF() { if (!CompON()) return; pinVAL(5, 0, conf.iddevice);  }
void setAlarmON() { if (AlarmON()) return; pinVAL(7, 1, conf.iddevice); tftpage=22; }
void setAlarmOFF() { if (!AlarmON()) return; pinVAL(7, 0, conf.iddevice); drawTFT(); }

int consignaCal()
{
  return conf.T[3];   // pendiente de mejorar  
}

void ArrancarCal()
{
  CALisON=true;
  REFisON=false;
  ACSisON=false;
  setV4VOFF();  // desactivar valvula de 4 vias
  setBCalON();  // encender bomba calefacción
  if ((millis()/1000-tempact[2])<=conf.CCC*60) return;  // esperar CCC minutos
  setBCapON();  // encender Bomba captador 
  if ((millis()/1000-tempact[3])<conf.CC*60) return;  // esperar CC minutos
  setComprON();  // encender compresor
}

void pararCal()
{ setComprOFF(); setBCapOFF(); setBCalOFF(); CALisON=false; }

void ArrancarRef()
{
  REFisON=true;
  CALisON=false;
  ACSisON=false;
  setV4VON();  // activar valvula de 4 vias
  setBCalON();  // encender bomba calefacción
  if ((millis()/1000-tempact[2])<=conf.CCC*60) return;  // esperar CCC minutos
  setBCapON();  // encender Bomba captador 
  if ((millis()/1000-tempact[3])<conf.CC*60) return;  // esperar CC minutos
  setComprON();  // encender compresor
}

void pararRef()
{ setComprOFF(); setBCapOFF(); setBCalOFF(); setV4VOFF(); REFisON=false;}

void ArrancarACS()
{
  ACSisON=true;
  CALisON=false;
  REFisON=false;
  setV4VOFF();  // desactivar valvula de 4 vias
  setBCalON();  // encender bomba calefacción
  setBACSON();  // encender bomba ACS y Válvula 3 vías
  if ((millis()/1000-tempact[2])<=conf.CCC*60) return;  // esperar CCC minutos
  setBCapON();  // encender Bomba captador 
  if ((millis()/1000-tempact[3])<conf.CC*60) return;  // esperar CC minutos
  setComprON();  // encender compresor
}

void pararACS()
{ 
  setComprOFF(); setBACSOFF(); setBCapOFF(); setBCalOFF(); ACSisON=false; }

void pararTODO()
{
  pararACS();
  pararCal();
  pararRef();
}

void setALARMA(byte tipoalarma)
{
  pinVAL(7, 1, conf.iddevice); 
  tftpage=22;
}

void checkAlarma()
{
  if (idbc[idBP]==1)
    { if (estalarma[5]==0) estalarma[5]=1; }
  else
    { estalarma[5]=0; }
  if (idbc[idHP]==1)
    { if (estalarma[6]==0) estalarma[6]=1; }
  else
    { estalarma[6]=0;  }
    
  byte i=9;
  while (i>0)
    { 
    Serial.print("i:"); Serial.print(i);
    Serial.print(" estalarma[i]:"); Serial.println(estalarma[i]);
    if (estalarma[i]==1) 
      {
     // tipoalarma=i; 
      Serial.println("ASIGNADO");
      break;
      }
    i--; 
    }
  tipoalarma=i;
  Serial.print("i:"); Serial.println(i);
  Serial.print("tipoalarma:"); Serial.print(tipoalarma);Serial.print("   ");
  for (byte i=0;i<10;i++) { Serial.print(estalarma[i]); Serial.print(","); } Serial.println();
}

void procesaBC() 
{
  checkAlarma();
  if (tipoalarma>0) 
    { 
    if (estalarma[tipoalarma]==1)
      {
      Serial.println("setAlarmON");
      setAlarmON(); 
      drawTFT();
      return; 
      }
    } 
  else 
    { 
    setAlarmOFF(); 
    }
  
  if (CALisON) consignaAct=consignaCal();
  if (REFisON) consignaAct=conf.FRO;
  if (ACSisON) consignaAct=conf.ECS;
#ifdef DEBUG
  // nada
#else
  demCAL=(Ai[0]<consignaCal();
  demACS=(Ai[0]<conf.ECS);
  demREF=(Ai[1]<conf.FRO);
#endif  
  if (ACSisON) if (conf.ACS==0) pararACS();   // se apaga ACS
  if (CALisON) if (conf.Cal==0) pararCal();   // se apaga Calefacción
  if (REFisON) if (conf.Ref==0) pararRef();   // se apaga Refrigeración

  /////////////////////////////
  if (conf.ACS==1)    // ACS encendida
    {
    if (idbc[idACS]==1)    // ACS solicitada por reloj
      {
      if (demACS)     //  por debajo de consigna
        {
        ArrancarACS();
        }
      else
        {
        setBACSOFF();
        ACSisON=false;
        if (conf.Cal==1)    // Calefacción encendida
          {
          if (idbc[idTerm]==1)   // Termostato activado
            {
            if (demCAL)    // demanda Cal
              ArrancarCal();
            else
              pararCal();
            }
          }
        else if (conf.Ref==1)      // refrigeración encendida
          {
          if (idbc[idTerm]==1)   // Termostato activado
            {
            if (demREF)    // demanda Ref
              ArrancarRef();
            else
              pararRef();
            }
          }
        else
          {
          pararACS();
          }
        }
      }
    else    // ACS desactivada reloj
      {
      if (conf.Cal==1)    // Calefacción encendida
        {
        setBACSOFF();
        ACSisON=false;
        if (idbc[idTerm]==1)   // Termostato activado
          {
          if (demCAL)    // demanda Cal
            ArrancarCal();
          else
            pararCal();
          }
        else
          {
          pararCal();
          }
        }
      else if (conf.Ref==1)
        {
        setBACSOFF();
        ACSisON=false;
        if (idbc[idTerm]==1)   // Termostato activado
          {
          if (demREF)    // demanda Ref
            ArrancarRef();
          else
            pararRef();
          }
        else
          {
          pararRef();
          }
        }
      else
        {
        pararACS();  
        }
      }
    }
  else     // ACS apagada
    {
    if (conf.Cal==1)    // Calefacción encendida
      {
      if (idbc[idTerm]==1)   // Termostato activado
        {
        if (demCAL)    // demanda Cal
          ArrancarCal();
        else
          pararCal();
        }
      else
        pararCal();
      }
    else if (conf.Ref==1)   // Refrigeración encendida
      {
      if (idbc[idTerm]==1)   // Termostato activado
        {
        if (demREF)    // demanda Ref
          ArrancarRef();
        else
          pararRef();
        }
      else
        {
        pararRef();
        }
      }
    else
      {
      pararRef();
      }
    }
}
