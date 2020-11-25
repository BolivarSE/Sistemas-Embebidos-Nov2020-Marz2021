#include <LiquidCrystal.h>
#include <Keypad.h> 
const byte fil = 4;     
const byte col = 4;    
String con1 = "ca900813";
int cont=0;
int cur=0;
char keys[fil][col] = {    
  {'7','8','9','a'},
  {'4','5','6','b'},
  {'1','2','3','c'},
  {'*','0','#','j'}
};

byte pinesFilas[fil] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[col] = {13,12,11,10}; // pines correspondientes a las columnas

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad keypad = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,fil,col);

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Presiona Tecla: ");
  lcd.setCursor(0,1);
}

void loop() {
  char key= keypad.getKey();
  if(key){
    cur=cur+1;
    lcd.print(key);
    Serial.println(key);
    if(key=='*'){
      cont=cont+1;
      if(cont==2){
        key='Z';
        lcd.setCursor(cur-2,1);
        lcd.print(key);
        Serial.println(key);
        cont=0;
      }
    }
    
    }
}
