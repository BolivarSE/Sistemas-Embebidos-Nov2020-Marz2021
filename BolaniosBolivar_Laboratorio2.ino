/* BOLAÑOS BOLIVAR
 *  LABORATORIO No 2: PERIFERICOS ESPECIFICOS
 *  
 * 
 */
 #include <LiquidCrystal.h>
 #include <MsTimer2.h>
  #include <TimerOne.h>
 LiquidCrystal lcd (22,23,24,25,26,27);
 const int led1=28,led2=29,led3=30,led4=31,s1=32,s2=33,s3=34,s4=35;
 int fun=0,sel=0,minutos=0,horas=0,cled=0,mh=0,mm=0;
 long pled;
 
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  attachInterrupt(2,encender,LOW);
  attachInterrupt(3,funcion,LOW);
}

void loop() {
                if(digitalRead(s1)== HIGH && fun==3 && sel==2 ){delay(200);Serial.println("Se encendio el sensor 1 ");}
                if(digitalRead(s2)== HIGH && fun==3 && sel==2){delay(200);Serial.println("Se encendio el sensor 2 ");}
                if(digitalRead(s3)== HIGH && fun==3 && sel==2){delay(200);Serial.println("Se encendio el sensor 3 ");}
                if(digitalRead(s4)== HIGH && fun==3 && sel==2){delay(200);Serial.println("Se encendio el sensor 4 ");}
if(fun==2){
  lcd.setCursor(0,0);
  lcd.print("                ");
  mh=analogRead(0);
  mh=map(mh,0,1023,0,24);
  mm=analogRead(1);
  mm=map(mm,0,1023,0,60);
  horas=mh;
  minutos=mm;
  if(minutos<10){
   lcd.setCursor(8,0);
   lcd.print("0"); 
  }
  if(minutos==60){
    lcd.setCursor(8,0);
    lcd.print("0"); 
    lcd.setCursor(10,0);
    lcd.print(" ");
    minutos=0;
    horas++;
    if(horas<10){
    lcd.setCursor(5,0);
    lcd.print("0"); 
    }
    if(horas==24){
      lcd.setCursor(6,0);
      lcd.print(" ");
      horas=0;
     }   
   }
  lcd.setCursor(0,0);
  lcd.print("Hora=");
  if(horas<10){
   lcd.setCursor(6,0);
  lcd.print(horas);
  }else{
    lcd.setCursor(5,0);
  lcd.print(horas);}
  lcd.setCursor(7,0);
  lcd.print(":");
  if(minutos<10){
   lcd.setCursor(9,0);
  lcd.print(minutos);
  }else{
    lcd.setCursor(8,0);
  lcd.print(minutos);}
  }

}

void encender(){
  if(sel==0){
    //Serial.println("Reloj encendido");
    MsTimer2::set(1000,reloj);
    MsTimer2::start();
    sel++;
    }else{
      if(sel==1){
        lcd.setCursor(0,1);      
        lcd.print("SELECCIONE MODO");
        sel++;
        }else{
          if(sel==2){
            MsTimer2::stop(); 
           // Timer1.detachInterrupt();
             lcd.setCursor(0,0);
             lcd.clear();
             lcd.setCursor(0,1);      
             lcd.clear();
             digitalWrite(led1,LOW);
             digitalWrite(led2,LOW);
             digitalWrite(led3,LOW);
             digitalWrite(led4,LOW);
              sel++;
              minutos=0;
              horas=0;
             
             }else{
              sel=0;
              } 
            }
          }
      }
  
  
void reloj(){
  minutos++;
 // Serial.println(String(minutos));
  if(minutos<10){
   lcd.setCursor(8,0);
   lcd.print("0"); 
  }
  if(minutos==60){
    lcd.setCursor(8,0);
    lcd.print("0"); 
    lcd.setCursor(10,0);
    lcd.print(" ");
    minutos=0;
    horas++;
    if(horas<10){
    lcd.setCursor(5,0);
    lcd.print("0"); 
    }
    if(horas==24){
      lcd.setCursor(6,0);
      lcd.print(" ");
      horas=0;
     }   
   }
  lcd.setCursor(0,0);
  lcd.print("Hora=");
  if(horas<10){
   lcd.setCursor(6,0);
  lcd.print(horas);
  }else{
    lcd.setCursor(5,0);
  lcd.print(horas);}
  lcd.setCursor(7,0);
  lcd.print(":");
  if(minutos<10){
   lcd.setCursor(9,0);
  lcd.print(minutos);
  }else{
    lcd.setCursor(8,0);
  lcd.print(minutos);}
  }

void funcion(){
  //Serial.println("Funcionando ");
  if(sel==2){
      if(fun==0){
        lcd.setCursor(0,1);     
        lcd.print("     MODO 1     ");
        Timer1.initialize(1000000);//1 segundo
        Timer1.attachInterrupt(leds);
        fun++;
        }else{
          if(fun==1){
             digitalWrite(led1,LOW);
             digitalWrite(led2,LOW);
             digitalWrite(led3,LOW);
             digitalWrite(led4,LOW);
            lcd.setCursor(0,1); 
            lcd.print("     MODO 2     ");
            cled=0;
            MsTimer2::stop(); 
            Timer1.detachInterrupt();
            fun++;
            }else{
              if(fun==2){
                digitalWrite(led1,LOW);
                digitalWrite(led2,LOW);
                digitalWrite(led3,LOW);
                digitalWrite(led4,LOW);
                MsTimer2::set(1000,reloj);
                MsTimer2::start();
                lcd.setCursor(0,1); 
                lcd.print("                ");
                delay(50);
                lcd.setCursor(0,1); 
                lcd.print("     MODO 3     ");
                fun++;
                }else{
                  fun=0;
                  lcd.setCursor(0,1); 
                  lcd.print("                ");       
                  }
              }
          
          }
    }
  }
  void leds(){
    if(cled<80){
      cled++;
      pled=random(0,4);
      switch(pled){
        case 0:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        break;
        case 1:
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        break;
        case 2:
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,LOW);
        break;
        case 3:
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,HIGH);
        break;
        default:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        break;
        }
      }else{
        delay(1000);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        }
    }
