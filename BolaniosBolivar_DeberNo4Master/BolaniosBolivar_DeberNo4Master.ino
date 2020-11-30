
#include <Wire.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
String salida;
 String dato;
int tam;
void setup() {
  Wire.begin(4); 
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);
  Serial.println("Ingrese el texto ");
}


void loop() {
  if(Serial.available()>0){
    delay(2000);
      dato=Serial.read();
      Serial.println(String(dato));
      lcd.print(String(dato));
      dato.toLowerCase();
      tam=dato.length()+1;
      Serial.println(tam);
      char vec [tam];
      dato.toCharArray(vec,tam);
      Wire.beginTransmission(4);
      Wire.write(vec,tam);
      Wire.endTransmission();
      Serial.println(" ");
      Serial.println(String("Enviado: ")+String(dato));
      
}}


void receiveEvent(int bytes){
   while(Wire.available() ){
      char vece=Wire.read();
      salida=salida+String(vece);
        
        }
        Serial.println(" ");
      Serial.println(String("Recibio: ")+String(salida));
        lcd.print(String(salida));
  }
