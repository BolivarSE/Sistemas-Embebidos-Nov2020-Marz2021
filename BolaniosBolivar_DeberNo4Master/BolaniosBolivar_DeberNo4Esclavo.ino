#include <Wire.h>
int tam;
String salida;
String dato;
int i=0;
char vec;
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println("Recibiendo el texto ");
  
}

void loop() {
  delay(1000);
   if(Serial.available()>0){
     Serial.println("Funcionando");
    Serial.println(String("Recibido ")+String(dato));}   

}
void receiveEvent(int bytes){
  while(Wire.available() ){
     vec=Wire.read();
    dato=dato+String(vec);}
   
    dato.toLowerCase();
      tam=dato.length()+1;
      char vecr [tam];
      dato.toCharArray(vecr,tam);
    for(i;i<tam-1;i++){
          switch(vecr[i]){
            case 'a':
              salida=salida+"@";
             break;
             case 'e':
              salida=salida+"#";
             break;
             case 'i':
              salida=salida+"!";
             break;
             case 'o':
              salida=salida+"*";
             break;
             case 'u':
              salida=salida+"$";
             break;
             default:
              salida=salida;
             break;
            }
          }
      salida.toLowerCase();
      int tame=dato.length()+1;
      char vece [tame];
      dato.toCharArray(vece,tame);
      Wire.beginTransmission(4);
      Wire.write(vece,tame);
      Wire.endTransmission();
  }
