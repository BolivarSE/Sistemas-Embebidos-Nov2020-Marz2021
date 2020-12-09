/* Deber No 6
 *  Bolaños Bolivar 
 *  Realizar un reloj con alarma ingresada por comunicación serial.  Los números sean vistos en displays.
 * 
 */

#include <MsTimer2.h>                    
#include <LiquidCrystal.h>                
LiquidCrystal lcd (13,12,11,10,9,8);      
const int led = 7;                      
int segundos =0,minutos =0,alarma1=0,alarma2 = 0,horas=0,enc1=0,enc2=0,aux1=1,aux2=1,valor;                                                                       
String dato;                       

void setup() {
  pinMode(led,OUTPUT);                       
  Serial.begin(9600);                 
  lcd.begin(16,2);                  
  attachInterrupt(0,alarma,LOW);                 
  Serial.println("Ingrese el minuto del reloj:");                              
}

void loop() {
  if(aux1==1){            
    if(Serial.available()>0){                 
     switch(enc1){                 
         case 0:                 
           dato=Serial.readString();                
           valor=dato.toInt();                 
           minutos=valor;                           
           enc1++;
           Serial.println("Ingrese la hora del reloj:");               
         break;
         case 1:
           dato=Serial.readString();                
           valor=dato.toInt();                 
           horas=valor;                        
           enc1++;                            
           aux1=0;
           Serial.println("Reloj establecido");
         break;
    }
  }
 }
  if(aux2==0){
    if(Serial.available()>0){            
        switch(enc2){
           case 0:
           dato=Serial.readString();            
           valor=dato.toInt();             
          alarma1=valor;             
           enc2++;             
           Serial.println("Ingrese la hora de la alarma:");            
           break;
           case 1:
           dato=Serial.readString();             
           valor=dato.toInt();            
           alarma2=valor;            
           enc2++;          
           aux2=1;
           Serial.println("Alarma Establecida");             
           break;
        }
    }
  }
}
void alarma(){   
  MsTimer2::set(1000,reloj);                
  MsTimer2::start();                         
  aux2=0;             
  enc2=0;             
}
void reloj(){             
  if(segundos<59){             
    segundos++;             
  }else{
    segundos=0;             
    if(minutos<59){             
      minutos++;             
    }else{
      minutos=0;             
      if(horas<23){             
        horas++;             
      }else{
          horas=0;             
       }
     }
   }
   lcd.clear();             
   lcd.setCursor(0,0);             
   lcd.print("Reloj: ");             
   lcd.setCursor(8,0);             
   lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));         
   lcd.setCursor(0,1);              
   lcd.print("Alarma: ");            
   lcd.setCursor(8,1);            
   lcd.print(String(alarma2)+String(":")+String(alarma1));          
   if(horas==alarma2){                   
    if(minutos==alarma1){           
      digitalWrite(led,HIGH);               
      }else{
       digitalWrite(led,LOW);                
      }
    }
}
