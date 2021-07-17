#include<Servo.h>

#define speed 220
#define m1s 11
#define m1d 12
#define m2s 5
#define m2d 6  
#define m1cw 0
#define m1acw 1
#define m2cw 1
#define m2acw 0

Servo s1,s2;
char c;
int pos1,pos2=160;


//int brk=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.attach(9);
  s2.attach(10);
  s1.write(10);
  s2.write(170);
 
  pinMode( m1s, OUTPUT);//m1 
  pinMode( m1d, OUTPUT);//m1
  pinMode( m2s, OUTPUT);//m2
  pinMode( m2d, OUTPUT);//m2
  //pinMode( 7, OUTPUT);//m1 b
  //pinMode( 2, OUTPUT);//m2 b
  pinMode( 3, OUTPUT);//s1
  pinMode( 5, OUTPUT);//s2
  
  //brake();
   }

void loop() 
  {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
  c=Serial.read();
  if(c=='F')
    forward();
  if(c=='B')
    backward();
  if(c=='R')
    slowright();
  if(c=='L')
    slowleft();
  if(c=='S')
     brake();
 /* if(c=='I')
     sharpright();
  if(c=='G')
     sharpleft();*/
  if(c=='W'||c=='w')
     restore();
  if(c=='U'||c=='u')
     dump(); 
  }
  }

void forward()
{ 
  //rotate m1 clockwise
  analogWrite( m1s,speed);
  //digitalWrite( ,0);
  digitalWrite( m1d,m1cw);
  //digitalWrite(7,brk);
  //rotate m2 clockwise
  analogWrite( m2s,speed);
  //digitalWrite( ,0);
  digitalWrite( m2d,m2cw);
  //digitalWrite(2,brk);
}

void backward()
{  
  //rotate m1 anticlockwise
  analogWrite( m1s,230);
  digitalWrite(m1d ,m1acw);
  //digitalWrite(7,brk);
 // digitalWrite( ,1);

  //rotate m2 anticlockwise
  analogWrite( m2s,230);
  digitalWrite( m2d,m2acw);
  //digitalWrite(2,brk);
  //digitalWrite( ,1);
}

void sharpright()
{  
  //rotate m1 clockwise
  analogWrite( m1s,speed);
  //digitalWrite( ,0);
  digitalWrite( m1d,m1cw);
  //digitalWrite(7,brk);

  //rotate m2 anticlockwise
  analogWrite( m2s,speed);
  digitalWrite( m2d,m2acw);
  //digitalWrite(2,brk);
  //digitalWrite( ,1);

  
}

void sharpleft()
{   
  //rotate m1 anticlockwise
  analogWrite( m1s,speed);
  digitalWrite( m1d,m1acw);
  //digitalWrite( 7,brk);
  
  //rotate m2 clockwise
  analogWrite(m2s ,speed);
  digitalWrite( m2d,m2cw);
  //digitalWrite( 2,brk);

  
}
void brake()
{ 
  analogWrite(m1s,0);
  analogWrite(m2s,0);
}

void dump()
{//pos=constrain(pos,0,180);
 s1.write(20);
 s2.write(160);
 //delay(50);
 }

void restore()
{//pos=constrain(pos,0,180);
  for(pos1=20;pos1<90;pos1++)
  { int t=180-pos1;
    s1.write(pos1);
    delay(30);
    s2.write(t);
    
    }
 /*for(pos=35;pos<=75;pos++)
 {int t=180-pos;
 s1.write(pos);
 s2.write(t);
 delay(10);*/
}
void slowleft()
{
  //stop m1 
  analogWrite( m1s,0);
  //digitalWrite( m1d,0);
  //digitalWrite( 7,brk);
  
  //rotate m2 clockwise
  analogWrite(m2s ,speed);
  digitalWrite( m2d,m2cw);
  //digitalWrite( 2,brk);

}
void slowright()
{
  //rotate m1 clockwise
  analogWrite( m1s,speed);
  digitalWrite( m1d,m1cw);
  //digitalWrite( 7,brk);
  
  //stop m2
  analogWrite(m2s ,0);
  //digitalWrite( m2d,1);
  //digitalWrite( 2,brk);

}
