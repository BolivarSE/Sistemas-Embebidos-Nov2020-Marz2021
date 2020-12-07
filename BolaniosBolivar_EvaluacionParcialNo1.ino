
//////////////////////////////////////////////////////////////////////////////////////////////////
/*  Bolaños Bolivar 
 *  Prueba Ejercicio
 *  Realice un programa que pueda ingresar vocales por comunicación serial y 
 *  responda un vector del mismo tamaño pero de forma ordenadas visualizado en una lcd.
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
String leer,ord;
int num,i=0,j=0;
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);  
  Serial.println("Ingrese las vocales desordenadas ");
}
void loop() {
  
  if(Serial.available()>0){
    delay(500);
  leer=Serial.readString();
  leer.toLowerCase(); 
  num=leer.length()+1; 
   char vec [num]; 
   char vec1 [num];
   leer.toCharArray(vec,num);
   j=0;
   for(i=0;i<num-1;i++){ 
      if(vec[i]=='a'){
        vec1[j]='a';
        j++;
        }}
    for(i=0;i<num-1;i++){        
      if(vec[i]=='e'){
        vec1[j]='e';
        j++;
        }}
    for(i=0;i<num-1;i++){ 
      if(vec[i]=='i'){
        vec1[j]='i';
        j++;
        }}
    for(i=0;i<num-1;i++){ 
      if(vec[i]=='o'){
        vec1[j]='o';
        j++;
        }}
     for(i=0;i<num-1;i++){ 
      if(vec[i]=='u'){
        vec1[j]='u';
        j++;
        }}
    
    
    lcd.setCursor(0,0);
    lcd.print("                ");
    delay(150);
    for(j=0;j<num-1;j++){ 
    lcd.setCursor(j,0);
     lcd.print(vec1[j]);
      }
     delay(500);
    }
    
    
    
    
    
  }  

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Bolaños Bolivar 
 *  Prueba Ejercicio
 *  Realice un convertidor de clave morse que se ingresa el mensaje 
 *  por comunicación serial y su resultado se observa en una lcd..
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
String leer,ord;
int num,i=0,j=0;
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);  
  Serial.println("Ingrese lo requerido a codificar ");

}

void loop() {
  
  if(Serial.available()>0){
    delay(500);
  leer=Serial.readString();
  leer.toLowerCase(); 
  num=leer.length()+1; 
   char vec [num]; 
   leer.toCharArray(vec,num);
    ord="";
   for(i=0;i<num-1;i++){ 
      if(vec[i]=='a'){
        ord=ord+".-";
        }
        if(vec[i]=='b'){
        ord=ord+"-...";

        }
        if(vec[i]=='c'){
        ord=ord+"-.-.";
        }
        if(vec[i]=='d'){
        ord=ord+"-..";
        }
        if(vec[i]=='e'){
        ord=ord+".";
        }
        if(vec[i]=='f'){
        ord=ord+"..-.";
        }
        if(vec[i]=='g'){
        ord=ord+"--.";
        }
        if(vec[i]=='h'){
        ord=ord+"....";
        }
        if(vec[i]=='i'){
        ord=ord+"..";
        }
        if(vec[i]=='j'){
        ord=ord+".---";
        }
        if(vec[i]=='k'){
        ord=ord+"-.-";
        }
        if(vec[i]=='l'){
        ord=ord+".-..";
        }
        if(vec[i]=='m'){
        ord=ord+"--";
        }
        if(vec[i]=='n'){
        ord=ord+"-.";
        }
        if(vec[i]=='o'){
        ord=ord+"---";
        }
        if(vec[i]=='p'){
        ord=ord+".--.";
        }
        if(vec[i]=='q'){
        ord=ord+"--.-";
        }
        if(vec[i]=='r'){
        ord=ord+".-.";
        }
        if(vec[i]=='s'){
        ord=ord+"...";
        }
        if(vec[i]=='t'){
        ord=ord+"-";
        }
        if(vec[i]=='u'){
        ord=ord+"..-";
        }
        if(vec[i]=='v'){
        ord=ord+"...-";
        }
        if(vec[i]=='w'){
        ord=ord+".--";
        }
        if(vec[i]=='x'){
        ord=ord+"-..-";
        }
        if(vec[i]=='y'){
        ord=ord+"-.--";
        }
        if(vec[i]=='z'){
        ord=ord+"--..";
        }
        if(vec[i]=='0'){
        ord=ord+"-----";
        }
        if(vec[i]=='1'){
        ord=ord+".----";
        }
        if(vec[i]=='2'){
        ord=ord+"..---";
        }
        if(vec[i]=='3'){
        ord=ord+"...--";
        }
        if(vec[i]=='4'){
        ord=ord+"....-";
        }
        if(vec[i]=='5'){
        ord=ord+".....";
        }
        if(vec[i]=='6'){
        ord=ord+"-....";
        }
        if(vec[i]=='7'){
        ord=ord+"--...";
        }
        if(vec[i]=='8'){
        ord=ord+"---..";
        }
        if(vec[i]=='9'){
        ord=ord+"----.";
        }
        }
    

    lcd.setCursor(0,0);
    lcd.print("                ");
    delay(150);
    lcd.setCursor(0,0);
    lcd.print(ord);
   
     delay(500);
    }
  }  

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Bolaños Bolivar 
 *  Realizar un convertidor de moneda donde se ingresan los valores por comunicación serial y 
 *  se debe observar por comunicación serial el valor ingresado y el resultado de la conversión por cada tipo de moneda. El cambio de conversión se lo realiza por dos interrupciones. La primera, actualiza el tipo de moneda de la fila 1 y la segunda interrupción de la fila 2.
   Los tipos de cambios son: 
   Todas las monedas requeridas las cambie a dolar por tanto:
   euro=0.82, dólar=1, peso colombiano=3466.00, peso argentino=81.73, franco suizo=0.89 y real=5.09.
 *  

*/

float mon1=0.00,mon2=0.00,franco=0.89,eu=0.82,pescol=3466.00,pesarg=81.73,real=5.09,c1=0.00,c2=0.00;
int mone1=0,mone=0;
String m1,m2;
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese la cantidad a tratar");
  attachInterrupt(0,fila1,LOW);
  attachInterrupt(1,fila2,LOW);
  
}

void loop() {
  if(Serial.available()>0){
    
      delay(1500);
      m1=Serial.readString();
      mon1=m1.toFloat();
      
    
    }
  
}

void fila1(){
  Serial.print("Entrada ");
  
  switch(mone){
      case 0:
      
      Serial.println("Euro: "+String(m1));
      mon2=eu;
      mone++;
      break;
      case 1:
      Serial.println("Dolar: "+String(m1));
      mon2=1;
      mone++;
      break;
      case 2:
      Serial.println("Peso Colombiano: "+String(m1));
      mon2=pescol;
      mone++;
      break;
      case 3:
      Serial.println("Franco: "+String(m1));
      mon2=franco;
      mone++;
      break;
      case 4:
      mon2=pesarg;
      Serial.println("Peso argentino: "+String(m1));

      mone++;
      break;
      case 5:
      mon2=real;
      
      Serial.println("Real: "+String(m1));

      mone++;
      break;
      default:
      
      mone=0;
      break;
      }
  
  }

 void fila2(){
  Serial.print("Salida ");
 

    switch(mone1){
      case 0:
      c1=mon1/mon2;
      c2=c1*eu;
      Serial.println("Euro: "+String(c2));

      mone1++;
      break;
      case 1:
      c1=mon1/mon2;
      c2=c1*1;
     Serial.println("Dolar: "+String(c2));

      mone1++;
      break;
      case 2:
      c1=mon1/mon2;
      c2=c1*pescol;
      Serial.println("Peso Colombiano: "+String(c2));
      
      mone1++;
      break;
      case 3:
      c1=mon1/mon2;
      c2=c1*franco;
       Serial.println("Franco: "+String(c2));

      mone1++;
      break;
      case 4:
      c1=mon1/mon2;
      c2=c1*pesarg;
      Serial.println("Peso argentino: "+String(c2));

      mone1++;
      break;
      case 5:
      c1=mon1/mon2;
      c2=c1*real;
      Serial.println("Real: "+String(c2));

      mone1++;
      break;
      default:
      
      mone1=0;
      break;
      
      }
    
    }
   
  
  
 
