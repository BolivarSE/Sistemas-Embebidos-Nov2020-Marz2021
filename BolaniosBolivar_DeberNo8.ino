/* DEBER 8: Realizar un código que el sistema se reinicia cada minuto, active el conversor análogo-digital 
   NOMBRE: Bolaños Bolivar
  
   Realice una lectura y vuelve el sistema a un modo sleep.
*/

#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>
int timer=0; 
int btn=0; 
int cont=0; 


void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,reloj);
  attachInterrupt(0,activacion,LOW);
}

void loop() {
  delay(1000);
}

void activacion(){
  switch(btn){
    case 0:
      timer = 60;
      Serial.println("ENCENDIDO");
      MsTimer2::start();
      btn++;
    break;

    case 1:
      Serial.println("APAGADO");
      timer=0;
      btn=0;
      cont=0;
      MsTimer2::stop();
      power_adc_disable();
    break;
  }
}

void reloj(){
  if(cont!=1){
    power_adc_disable();
  }
  else{
    power_adc_enable();
    delay(50);
    Serial.println(String("Lectura: ")+String(analogRead(0)));
  }

  if(cont==60){
    cont=0;
  }
  
  cont++;
  power_adc_disable();     
}
