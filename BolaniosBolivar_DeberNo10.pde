int x=600,y=400;
long r=0,g=0,b=0;
void setup (){
size(1200,800); //size(displayWidth,displayHeight);
background(#505050);
}

void draw(){
background(#505050);
stroke(#505050);
fill(random(0,250),random(0,250),random(0,250));
ellipse(x,y,50,50);

 
}
void keyPressed(){
  
  switch(keyCode){
    /*
    37 izq
    40 abajo
    39 derecha
    38 arriba
    */
  case 37:
   if(x>0){
      x=x-10;}else{
      x=1200;}
  break;
  case 39:
  if(x<1200){
      x=x+10;}else{
      x=0;}
  break;
  case 38:
 if(y>0){
   y=y-10;}else{
  y=800;}
  break;
  case 40:
  if(y<800){
   y=y+10;}else{
    y=0;}
  break;

  
}
}
