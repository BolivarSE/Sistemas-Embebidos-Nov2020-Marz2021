import processing.serial.*;

int estatura=0, aux=0,aux1=0, aux2=0,fil=0,col=0,n=0;
float peso=0;
Serial port;
int matrizr[][]={{0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},};
int matriz[][]={
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
  
  
  void setup(){
  size(1000,600);
   port= new Serial(this, "COM10",9600);
  
}
void draw(){
  background(0);
  conectar();
  ejes();
  graficar();
  nuevosP();


}
void conectar(){
  while (port.available() > 0) {

    estatura = port.read();
    println(estatura);
    peso=port.read();
    println(peso);
    matrizr[aux2][0]=estatura;
    matrizr[aux2][1]=(int)peso;
    
    println(matrizr[aux2][0]);
    println( matrizr[aux2][1]);
    aux2++;
 
 } 
 
} 
void ejes(){
for(aux=0;aux<12;aux++){
  strokeWeight(1);
  stroke(255);
  line(1000,aux*50,0,aux*50);}
  
  for(aux1=0;aux1<10;aux1++){

    strokeWeight(1);
  stroke(255);
  line(aux1*100,600,aux1*100,0);}
  fill(#FF0000);
  strokeWeight(5);
  stroke(#FF0000);
  line(200,600,200,0);
   strokeWeight(5);
  stroke(#FF0000);
  line(1000,550,100,550);
  
  fill(#0BFF00);
  textSize(20);
  text("PESO",110,40);
  text("90",160,100);
  text("80",160,150);
  text("70",160,200);
  text("60",160,250);
  text("50",160,300);
  text("40",160,350);
  text("30",160,400);
  text("20",160,450);
  text("10",160,500);
  text("0",170,570);
  //
  text("ALTURA",50,570);
  text("155",300,570);
  text("160",400,570);
  text("165",500,570);
  text("170",600,570);
  text("175",700,570);
  text("180",800,570);
  text("185",900,570);
}
void graficar(){
  
  for(fil=0;fil<14;fil++){
  stroke(#0326FF);
  fill(#0326FF);
  ellipse(200+((matriz[fil][0]-150)*20),550-(matriz[fil][1]*5),5,5);
  
  }
  strokeWeight(2);
  stroke(#EDFF03);
   line(400,275,800,150);
 

}
void nuevosP(){
  for(fil=0;fil<aux2;fil++){
    
  stroke(#E103FF);
  fill(#E103FF);
  ellipse(200+((matrizr[fil][0]-150)*20),550-(matrizr[fil][1]*5),6,6);
  
  }
  
}
