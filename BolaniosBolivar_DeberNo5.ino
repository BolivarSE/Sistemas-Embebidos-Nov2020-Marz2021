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
 int li=0;
void setup() {
  servo1.attach(6);
  Serial.begin(9600);
  attachInterrupt(0,mod,LOW);
}

void loop() {
  
  if(modo==2){
    if(Serial.available()>0){
      delay(500);
      limit=Serial.readString();
      li=limit.toInt();
      if(li<=180 && li>=0){
      servo1.write(li);
      delay(500);
      }else{
        Serial.println("Dato erroneo ingrese nuevamente");
        delay(500);
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
   
    Serial.println("Fin del programa ");
    modo=0;
    li=0;
    servo1.write(li);
    break;  
    default:
    modo=0;
    break;  
    }
  }
