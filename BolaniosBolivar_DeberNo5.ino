/* Deber No 5
 *  Bolaños Bolivar
 *  
 * Realizar un programa que mediante interrupciones tenga 3 modos: Inicio del sistema, giro de motor y fin de programa. 
 * El giro debe ser ingresado por comunicación serial.
 */
 #include <Servo.h>
 Servo servo1;
 int modo=0;
 String limit;
 int li=0,ciclo=0;
void setup() {
  servo1.attach(6);
  Serial.begin(9600);
  attachInterrupt(0,mod,LOW);
}

void loop() {
  delay(1000);
  if(modo==2){
    if(Serial.available()>0){
    
    while(ciclo==0){
      delay(3000);
      limit=Serial.readString();
      li=limit.toInt();
      if(li<=180 && li>=0){
      servo1.write(li);
      ciclo++;
      delay(1000);
      }else{
        ciclo=0;
        Serial.println("Dato erroneo ingrese nuevamente");
        delay(1000);
        }
      }
     }
    }
  
}

void mod(){
  switch(modo){
    case 0:
    Serial.println("Inicio del sistema ");
    modo++;
    break;
    case 1:
    Serial.println("Giro del motor de 0-180 ");
    modo++;
    break;
    case 2:
    ciclo=0;
    Serial.println("Fin del programa ");
    modo=0;
    li=0;
    servo1.write(li);
    break;  
    default:
    ciclo=0;
    modo=0;
    break;  
    }
  }
