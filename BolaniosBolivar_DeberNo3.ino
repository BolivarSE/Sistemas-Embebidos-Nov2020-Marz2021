
const int A=8; //decodificador
const int B=9; //decodificador
const int C=10; //decodificador
const int D=11; //decodificador
const int btn=7;
const int unidades=12;
int num;
int cont=0;
int i=0;
String dato;
String pregunta;
String respuesta;

void setup() {
  Serial.begin(9600);
  Serial.println("PRESIONE ENTER PARA EMPEZAR ");
 pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  digitalWrite(unidades,HIGH);
  pinMode(unidades,OUTPUT);


}

void loop() {
  
  delay(1000);
  if(Serial.available()>0){
    Serial.println("Responda con si o no");
    Serial.println(" ");
    
for(i=0;i<5;i++){
   num=random(0,8);
   delay(500);
   switch (num){
    case 0:
    pregunta="El Titanic en su viaje inaugural va desde Southampton, Inglaterra hasta Nueva York, Estados Unidos.";
    respuesta="si";
    break;
    case 1:
    pregunta="Brasil ha sido el unico pais latinoamericano que ha organizado unos Juegos Olimpicos. ";
    respuesta="no";
    break;
    case 2:
    pregunta="En el anio 2017 se hizo el primer trasplante de cerebro de seres humanos. ";
    respuesta="si";
    break;
    case 3:
    pregunta="Los asesinos en serie tienen un coeficiente intelectual inferior a la media. ";
    respuesta="no";
    break;
    case 4:
    pregunta="Las moscas macho viven en promedio 5 anios. ";
    respuesta="no";
    break;
    case 5:
    pregunta="Durante la adultez nuestro cuerpo tiene 300 huesos mientras que en la niniez 206. ";
    respuesta="no";
    break;
    case 6:
    pregunta="Guillermo Marconi en 1943 se reafirma como el inventor de la radio por encima de Nikola Tesla ";
    respuesta="no";
    break;
    case 7:
    pregunta="Las Cicladas es un lugar real. ";
    respuesta="si";
    break;
    }
    Serial.println(String(pregunta));
    delay(5000);
    dato=Serial.readString();
    
    dato.toLowerCase();
    Serial.println(' ');
   if(dato==respuesta){
      delay(300);
      Serial.println("Respuesta Correcta");
          cont++;
        }else{
            Serial.println("Respuesta Incorrecta");
            }
          
          
          contador(cont);
          delay(200);
          }
          delay(5000);
          cont=0;
          contador(cont);}}




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
