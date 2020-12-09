/*
 *Deber No7
 *Bolaños Bolivar
 *Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. 
 *Como estado inicial, la contraseña es de 4 dígitos que son: 4563. 
 */
 #include <EEPROM.h>
 int enc=0,leer,pas,num=0;   
 int pass = 4563;   
 String dato;       
void setup() {
pas=EEPROM.read(0);       
EEPROM.update(0,4563);     
Serial.begin(9600);  
Serial.println("INICIO DEL SISTEMA");          
attachInterrupt(0,encender,LOW);   
attachInterrupt(1,contar,LOW);       
}
void loop() {
    if(enc==2){                   
      if(num==1){             
        if(Serial.available()>0){          
          dato=Serial.readString();                
          pas=dato.toInt();            
          EEPROM.update(0,pas);       
          Serial.println("Contrasenia Guardada");          
        }
      }
      if(num==0){             
        if(Serial.available()>0){              
          dato=Serial.readString();            
          leer=dato.toInt();             
          if(pass==leer){             
            Serial.println("Ingreso Correcto");              
          }else{
            Serial.println("Ingreso Incorrecto");            
          }
        }
      }
    }
}
void encender(){                  
  switch(enc){                       
    case 0: 
 
    Serial.println("Ingrese la accion a realizar");            
    enc++;     
    break;
    case 1:
      switch(num){
        case 1:
          Serial.println("Actualice la contrasenia");             
        break;
        case 0:
          Serial.println("Verificar contrasenia");             
        break;
      }
    enc++;              
    break;
    case 2:
    Serial.println("Accion procesada");          
    num=0;           
    enc=0;               
    break;
  }
}
void contar(){       
  if(enc==1){           
    switch(num){
      case 0:
        Serial.println("Actualizar contrasenia");            
        num++;              
      break;
       case 1:
       Serial.println("Verificar contrasenia");            
        num=0;               
       break;
    }
  }
}
