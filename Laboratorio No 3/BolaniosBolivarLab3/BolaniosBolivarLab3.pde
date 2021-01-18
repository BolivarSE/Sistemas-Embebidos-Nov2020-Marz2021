import processing.serial.*;
import ddf.minim.*;


PImage img, fondo,ene,puntaje;
PFont fuente;
float posx=10,posy=240,punt=0,posex1=1000,posex2=1500,posex3=1200,posex4=1600,posex5=2000,posex6=1500,posex7=1300,posex8=1100,bolx,boly;
String dato;
int i,fil=0,col=0,vidas=3,bx=10,menu=0;
boolean pun=true;

Serial port;
AudioPlayer play1;


void setup(){
  frameRate(60);
  size(900,506);
  fondo=loadImage("espacio.jpg");
  background(fondo);
  fuente=loadFont("LucidaBright-DemiItalic-48.vlw");
  img=loadImage("nave.png");
  ene=loadImage("enemigo.png");
  puntaje=loadImage("bola.png");
 port= new Serial(this, "COM10",9600);

}

void draw(){
   background(fondo);
  
switch(menu){
  case 0:
   menuP();
  break;
  case 1:
  texto();
  enemigo();
  mover();
  puntos();
  masPuntos();
  muerte();
  break;
  case 2:
  perder();
  break;
  case 3:
  ganar();
  break;
}
 
      
    
  }
  
void mover(){
  image(img,posx,posy,70,70);
  tint(0,50);
  image(img,posx+5,posy+5,70,70);
  noTint();
   while (port.available() > 0) {

   dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
 switch(dato){
   case "A":
   for(i=0;i<10;i++){
     posx=posx-1;
   }
   
   
  println(" "+posx+"-"+posy);
   print("A");
   
   break;
   case "B":
      posx=posx+20;
      
      println(" "+posx+"-"+posy);
      
      print("B");
       
   break;
      case "C":
        posy=posy-20;
        
          println(" "+posx+"-"+posy);
        
        print("C");
   break;
       case "D":
        posy=posy+20;
        
         println(" "+posx+"-"+posy);
        print("D");
   break;
 }}}

void enemigo(){
  

      
  if(posex1>-100){
    posex1=posex1-1;
      image(ene,posex1,40,70,70);
      tint(0,50);
      image(ene,posex1-5,40-5,70,70);
      noTint();
  }else{
  posex1=1000;
  }
   if(posex2>-100){
    posex2=posex2-5;
      image(ene,posex2,100,70,70);
      tint(0,50);
      image(ene,posex2-5,100-5,70,70);
      noTint();
  }else{
  posex2=1500;
  }
  if(posex3>-100){
    posex3=posex3-2;
      image(ene,posex3,200,70,70);
      tint(0,50);
      image(ene,posex3-5,200-5,70,70);
      noTint();
  }else{
  posex3=1200;
  }
  if(posex4>-100){
    posex4=posex4-2;
      image(ene,posex4,280,70,70);
      tint(0,50);
      image(ene,posex4-5,280-5,70,70);
      noTint();
  }else{
  posex4=1600;
  }
     
     
  if(posex6>-175){
    posex6=posex6-1;
      imageMode(CENTER);
      image(ene,posex6,240,200,200);
      tint(0,50);
      image(ene,posex6-5,240-5,200,200);
      noTint();
  }else{
  posex6=1500;
  } 
    if(posex7>-100){
    posex7=posex7-4;
      image(ene,posex7,400,70,70);
      tint(0,50);
      image(ene,posex7-5,400-5,70,70);
      noTint();
  }else{
  posex7=1300;
  }  
 if(posex8>-100){
    posex8=posex8-2;
      image(ene,posex8,300,70,70);
      tint(0,50);
      image(ene,posex8-5,300-5,70,70);
      noTint();
  }else{
  posex8=1100;
  }  

}

void puntos(){
  if(pun==true){
  bolx=random(50,850);
  boly=random(50,450);
  println(" "+bolx+"-"+boly);
  pun=false;
  }
  image(puntaje,bolx,boly,50,50);
  tint(0,50); 
  image(puntaje,bolx-5,boly-5,50,50);
  noTint(); 
  
 

}
void texto(){
  textFont(fuente);
  textSize(15);
  text("Puntaje= "+punt,20,30);
  text("Vidas= "+vidas,20,45);
}

void masPuntos(){
   if(((posx<=(bolx+20) && posx>(bolx-20))==true) && ((posy<=(boly+20) && posy>(boly-20))==true)){
    punt++;
    pun=true;
  
  }
  if(punt==3){
    menu=3;
  }
 

}

 void muerte(){
  if(((posx<=(posex1+10) && posx>(posex1-10))==true) && ((posy<=(50) && posy>(30))==true)){
    vidas--;
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }

   if(((posx<=(posex2+10) && posx>(posex2-10))==true) && (posy==100)){
    vidas--;
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }
    
 if(((posx<=(posex3+10) && posx>(posex3-10))==true) && posy==200){
    vidas--;
     posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }
    
    if(((posx<=(posex4+10) && posx>(posex4-10))==true) && posy==280){
    vidas--;
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }
    
      if(((posx<=(posex6+50) && posx>(posex6-50))==true) && posy==240){
    vidas--;
     posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }
    
    if(((posx<=(posex7+10) && posx>(posex7-10))==true) && posy==400){
    vidas--;
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }
    
    if(((posx<=(posex8+10) && posx>(posex8-10))==true) && posy==300){
    vidas--;
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
    }  
    
    if(vidas==0){
      menu++;
    }
    }
    
    
    void menuP(){
      posx=10;
      posy=240;
      punt=0;posex1=1000;
      posex2=1500;posex3=1200;
      posex4=1600;
      posex5=2000;posex6=1500;posex7=1300;posex8=1100;
      textFont(fuente);
      textSize(45);
      text("Presione un boton para empezar ",100,250);
      
       while (port.available() > 0) {

   dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
 switch(dato){
   case "A":
  
   menu=menu+1;
   
 
   break;
   case "B":
    
       menu=menu+1;  
       
   break;
      case "C":
           menu=menu+1;
   break;
       case "D":
          menu=menu+1;
   break;
 }
      
    
       }}
       
       void perder(){
      vidas=3;
      punt=0;
      textFont(fuente);
      textSize(45);
      text("Perdiste ",380,250);
     
      text("Presione para volver a intentar ",100,330);
      
       while (port.available() > 0) {

   dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
 switch(dato){
   case "A":
  
   menu=1;
   
 
   break;
   case "B":
    
       menu=1;  
       
   break;
      case "C":
           menu=1;
   break;
       case "D":
          menu=1;
   break;
 }
      
    
       }}
        void ganar(){
      vidas=3;
      punt=0;
      textFont(fuente);
      textSize(45);
      text("¡Ganaste!",380,250);
      text("Presione para volver al inicio ",100,290);
      
       while (port.available() > 0) {

   dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
 switch(dato){
   case "A":
  
   menu=0;
   
 
   break;
   case "B":
    
       menu=0;  
       
   break;
      case "C":
           menu=0;
   break;
       case "D":
          menu=0;
   break;
 }
       }}
