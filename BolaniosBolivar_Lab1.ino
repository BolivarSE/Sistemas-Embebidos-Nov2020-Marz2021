#include <LiquidCrystal.h>

String cod1="ca900813";
String cod2="aj881112";
String cod3="ja890109";
String text1="BIENVENIDO CARLOS ARIAS";
String text2="BIENVENIDO ANDRES JUAREZ";
String text3="BIENVENIDO JAVIER ANDRADA";
String ct1,ct2,ct3;
int ver1=0,ver2=0,ver3=0;
int i=0;
String dato;
const int rs = 13, en =12 , d4 = 11, d5 = 10, d6 = 9, d7 = 8;
int but=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(but,INPUT);
  Serial.begin(9600);
  Serial.println("Ingrese credenciales");
  lcd.begin(16, 2);
  lcd.print("Ingrese el codigo ");

}

void loop() {
  
  
  if(Serial.available()>0){
    dato=Serial.readString();
    
    if(dato==cod1){
        lcd.print("Ingreso correcto!");
        lcd.clear();
        Serial.println(" ");
        Serial.println("Ingreso correcto!");
        Serial.println("BIENVENIDO CARLOS ARIAS");
        Serial.println("Ingrese credenciales");
        Serial.println(" ");
        ver1=1;
        delay(500);
         for(i=15;i>=-7;i--)
              {
                lcd.clear();
                lcd.setCursor(i, 0);
                lcd.print(text1);
                delay(500);
              }
           
              delay(500);
              lcd.clear();
              lcd.print("Ingrese el codigo ");
      }
      
   else{
      if(dato==cod2){
        lcd.print("Ingreso correcto!");
        Serial.println(" ");
        Serial.println("Ingreso correcto!");
        Serial.println("BIENVENIDO ANDRES JUAREZ");
        Serial.println("Ingrese credenciales");
        Serial.println(" ");
        ver2=1;
        lcd.clear();
        delay(500);
         for(i=17;i>=-8;i--)
              {
                lcd.clear();
                lcd.setCursor(i, 0);
                lcd.print(text2);
                delay(500);
              }
              delay(500);
              lcd.clear();
              lcd.print("Ingrese el codigo ");
              }else{
                if(dato==cod3){
                  Serial.println(" ");
              Serial.println("Ingreso correcto!");
              Serial.println("BIENVENIDO JAVIER ANDRADA");
              Serial.println("Ingrese credenciales");
              Serial.println(" ");
              lcd.print("Ingreso correcto!");
              ver3=1;
              lcd.clear();
              delay(500);
              
               for(i=18;i>=-9;i--)
                    {
                      lcd.clear();
                      lcd.setCursor(i, 0);
                      lcd.print(text3);
                      delay(500);
                    }
              lcd.clear();
              lcd.print("Ingrese el codigo ");
      
      }else{
      lcd.clear();
      lcd.println("USUARIO INVALIDO");
      delay(1000);
      lcd.print("Ingrese el codigo ");
              Serial.println(" ");
              Serial.println("USUARIO INVALIDO");
              Serial.println("Ingrese credenciales");
              Serial.println(" ");
      
      
    }
      }
      }}

if(digitalRead(but)==LOW){
  delay(250);
  if(ver1==1){
    ct1="USUARIO CARLOS ARIAS HA INGRESADO A LA EMPRESA";
    ver1=0;
  }
  else
    ct1="USUARIO CARLOS ARIAS NO HA INGRESADO A LA EMPRESA";
  if(ver2==1){
    ct2="USUARIO ANDRES JUAREZ HA INGRESADO A LA EMPRESA";
    ver2=0;
  }
  else
    ct2="USUARIO ANDRES JUAREZ NO HA INGRESADO A LA EMPRESA";
  if(ver3==1){
    ct3="USUARIO JAVIER ANDRADA HA INGRESADO A LA EMPRESA";
    ver3=0;
  }
  else
    ct3="USUARIO JAVIER ANDRADA NO HA INGRESADO A LA EMPRESA";
  
  Serial.println("");
  Serial.println(ct1);
  Serial.println(ct2);
  Serial.println(ct3);
  Serial.println("");
  Serial.println("Ingrese credenciales");
  
}
    }
