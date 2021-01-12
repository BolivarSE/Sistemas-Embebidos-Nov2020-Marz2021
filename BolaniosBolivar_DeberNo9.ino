/* DEBER 9:
   NOMBRE: Bolaños Bolivar
    
    OBJETIVO: Realice un programa que mediante un conversor análogo-digital se configure el tiempo de reinicio del perro guardián 
    tiempos seleccionados por el usuario. Envíe mensajes por comunicación serial validando todo el proceso. 
*/

#include <avr/wdt.h> 
#include <MsTimer2.h>

int tiempo=0;
int tiempoaux=1;
int cont=0;
int encender=0;
int aux=0;


void setup(){
  Serial.begin(9600);
  Serial.println("INICIO");
  MsTimer2::set(1000, reset);
  attachInterrupt(0,valor,LOW);
}

void loop() {
  if(encender==1){
    aux = analogRead(0);
    tiempo = map(aux, 0, 1023, 0, 60);
    delay(50);
    if (tiempoaux!=tiempo){
      Serial.println(String("Tiempo: ")+String(tiempo));  
    }
    tiempoaux=tiempo;
  }
}

void reset() {
  cont++;
  if (cont==tiempo){
  wdt_disable();
  wdt_enable(WDTO_500MS);
  }
}

void valor(){
  switch(encender){
    case 0:
      
      Serial.println("Configure el tiempo de reinicio mediante el potenciometro");
      encender++;
    break;
    
    case 1:
      Serial.println(String("Tiempo de reinicio: ")+String(tiempo)+String(" segundos"));
      MsTimer2::start();
      encender=0;
    break;
  }
}
