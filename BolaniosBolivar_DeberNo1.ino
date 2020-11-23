/* CAP II : Puertos digitales
Deber No 1: Puertos Digitales
Objetivos:
Realizar un programa que accione mediante 4 switchs a un juego de luces diferente. Es decir.

sw3   sw2  sw1  sw0

0        0       0        1            Juego 1

0        0       1        0            Juego 2

0        1       0        0            Juego 3

1        0       0        0            Juego 4

 

Juego #1

Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones

Juego #2

Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones

Juego #3

Se encienden secuencialmente cada uno ellos (flexible a su criterio)

Juego #4

Su propio diseño de juego. 
                       
*/
const int led1=8; 
const int led2=9; 
const int led3=10; 
const int led4=11; 
const int led5=12; 
const int led6=13; 
const int btn1=4; 
const int btn2=5; 
const int btn3=6; 
const int btn4=7; 
int i=0; //variable para ciclo if
int j=0;
int k=0;
int l=0;
void setup() {
  pinMode(led1,OUTPUT); 
  pinMode(led2,OUTPUT); 
  pinMode(led3,OUTPUT); 
  pinMode(led4,OUTPUT); 
  pinMode(led5,OUTPUT); 
  pinMode(led6,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);
}
void loop() {


  if(digitalRead(btn1)==HIGH && i<10){
     delay(200);
     digitalWrite(led1,LOW);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,LOW);
     digitalWrite(led4,HIGH);
     digitalWrite(led5,LOW);
     digitalWrite(led6,HIGH);
     delay(200);
     i++;
    } else{ 
      delay(200);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      }



  if(digitalRead(btn2)==HIGH && j<10){
     delay(200);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,LOW);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,LOW);
     digitalWrite(led5,HIGH);
     digitalWrite(led6,LOW);
     delay(200);
     j++;
    }else{ 
      delay(200);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      }

   if(digitalRead(btn3)==HIGH) {
    
    delay(200);
     digitalWrite(led1,HIGH);
     delay(200);
     digitalWrite(led2,HIGH);
     delay(200);
     digitalWrite(led3,HIGH);
     delay(200);
     digitalWrite(led4,HIGH);
     delay(200);
     digitalWrite(led5,HIGH);
     delay(200);
     digitalWrite(led6,HIGH);
     delay(500);
     digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
    }
    else{
      
      delay(200);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      }


   if(digitalRead(btn4)==HIGH) {
    
     delay(200);
     digitalWrite(led1,HIGH);
     delay(200);
     digitalWrite(led3,HIGH);
     delay(200);
     digitalWrite(led5,HIGH);
     delay(500);
     digitalWrite(led2,HIGH);
     delay(200);
     digitalWrite(led4,HIGH);
     delay(200);
     digitalWrite(led6,HIGH);
     delay(500);
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
     digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
     digitalWrite(led6,LOW);
    }
    else{
      
      delay(200);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      }
      
      


}
