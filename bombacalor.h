  /////// Bomba de calor
  #define hpIACS I0     // Interruptor modo ACS forzado
  #define hpIFrio I1    // Interruptor modo frío
  #define hpIBP I2      // BP Manómetro baja presión activado
  #define hpIHP I3      // HP Manómetro alta presión activado
  #define hpOBPRI O0    // Bomba primario
  #define hpOBSEC O1    // Bomba secundario
  #define hpOCMP O2     // Compresor
  #define hpOVACS O3    // Válvula ACS  
  #define hpOBACS O4    // Bomba ACS
  #define hpOALAR O5    // Alarma   (piloto u otros usos)
  #define hpOENC O6     // Encendido/Apagado por software 
  #define hpOXX6 O7     // LIBRE
  #define hptIDA 0      // Temperatura Ida Secundario (Calefacción)
  #define hptRET 1      // Temperatura Retorno Secundario (Calefacción)
  #define hptICAP 2     // Temperatura Ida Primario (Captador)
  #define hptRCAP 3     // Temperatura Retorno Primario (Captador)
  #define hptEXT 4      // Temperatura exterior 
  #define hptACS 5      // Temperatura ACS
  #define hptDESC 6     // Temperatura descarga compresor
  #define hptASP 7      // Temperatura aspiración compresor

void procesahp()
  {
  
  }
  
void task1hp()
{
  tini=millis();
  countfaulttime++;   // si se hace mayor que TempDesactPrg,desactiva ejecucion programas dependientes de fecha
  leevaloresAN();
  procesahp();
  procesaeventos();
  procesaTimeMax();
  for (byte j=0; j<maxsalrem; j++)
    if (conf.idsalremote[j]>0)
      if ((conf.senalrem[j]==6) || (conf.senalrem[j]==7)) contaremote[j]++;
  mact1 = millis();
}

void task10hp()
{
  tini=millis();
  countfaulttime++;   // si se hace mayor que TempDesactPrg,desactiva ejecucion programas dependientes de fecha
  leevaloresOW();
}


