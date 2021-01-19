
/*
 * Deber No 11
 * Bolivar Bolaños
 Capitulo: Aprendizaje de maquina-Regresion lineal 
 objetivo: modelo de regresion lineal exponencial
*/
int matriz [14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};


int col = 0;  
int fil = 0; 
int Ex = 0;  
float Ey1 = 0;  
float Exy1 = 0;  
long int Ex2 = 0;  
long int Ex_2 = 0;  
int n = 14;  
float B;  
String dato;  
int estatura;  
float peso;
float A;
float aux = 0;
float m1 = 0;

void setup() {
  Serial.begin(9600);
  for(;fil<n;fil++){
    Ex = Ex+matriz[fil][0];
    Ey1 = Ey1+log(matriz[fil][1]);
    Exy1 = Exy1+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2 = Ex2+pow(matriz[fil][0],2);
  }
  Ex_2 = pow(Ex,2);
  aux = float(n*Exy1)-float(Ex*Ey1);
  m1 = n*Ex2-Ex_2;
  B = float(aux/m1);
  float my1 = Ey1/n;
  float mx = Ex/n;
  float Bmx = B*mx;
  float A1 = my1-Bmx;
  A = exp(A1);
  Serial.println("El modelo es: ");
  Serial.println(String("Y = ")+String(A)+String(" * ")+String("e^(")+String(B)+String("*x)"));
  Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
    dato = Serial.readString();
    estatura = dato.toInt();
    peso = A*exp(B*estatura);
    Serial.println(String(" Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
  }
}
