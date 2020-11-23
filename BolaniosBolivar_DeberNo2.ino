/*CAP II: PUERTOS DIGITALES
 * Deber No 2: manejo de display de 7 segmentos decodificador 7447
 * objetivo: Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99. 
 * 
 */
const int A=8; //decodificador
const int B=9; //decodificador
const int C=10; //decodificador
const int D=11; //decodificador
const int btn=7;
const int unidades=12;
const int decenas=13;
int cont=0;
int uni;
int dec;
void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(btn,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
}

void loop() {
  if(digitalRead(btn)==HIGH){
      delay(300);
      if(cont<=26){
        cont++;
        switch(cont){
        case 1:
          uni=1;
          dec=0;
          break;
        case 2:
          uni=2;
          dec=0;
          break;
        case 3:
          uni=3;
          dec=0;
          break;
        case 4:
          uni=5;
          dec=0;
          break;
         case 5:
          uni=7;
          dec=0;
          break;
         case 6:
          uni=1;
          dec=1;
          break;
         case 7:
          uni=3;
          dec=1;
          break;
         case 8:
          uni=7;
          dec=1;
          break;
         case 9:
          uni=9;
          dec=1;
          break;
         case 10:
          uni=3;
          dec=2;
          break;
         case 11:
          uni=9;
          dec=2;
          break;
         case 12:
          uni=1;
          dec=3;
          break;
         case 13:
          uni=7;
          dec=3;
          break;
         case 14:
          uni=1;
          dec=4;
          break;
         case 15:
          uni=3;
          dec=4;
          break;
         case 16:
          uni=7;
          dec=4;
          break;
         case 17:
          uni=3;
          dec=5;
          break;
         case 18:
          uni=9;
          dec=5;
          break;
         case 19:
          uni=1;
          dec=6;
          break;
         case 20:
          uni=7;
          dec=6;
          break;
         case 21:
          uni=1;
          dec=7;
          break;
         case 22:
          uni=3;
          dec=7;
          break;
         case 23:
          uni=9;
          dec=7;
          break;
         case 24:
          uni=3;
          dec=8;
          break;
         case 25:
          uni=9;
          dec=8;
          break;
         case 26:
          uni=7;
          dec=9;
          break;
          
        }
         
    }else{
      cont=0;
      }
    digitalWrite(unidades,HIGH);
         digitalWrite(decenas,LOW);
         contador(uni);
         delay(200);
         digitalWrite(unidades,LOW);
         digitalWrite(decenas,HIGH);
         contador(dec);
         delay(200); 
          
}}

void contador (int i){
  switch(i){
      case 0:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
      break;
      case 1:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
      break;
      case 2:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
      break;
      case 3:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
      break;
      case 4:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
      break;
      case 5:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
      break;
      case 6:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
      break;
      case 7:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
      break;
      case 8:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
      break;
      case 9:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
      break;
      }
  }
