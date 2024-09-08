#include <Servo.h>
Servo motor;
#define ir1 A2
#define ir2 A3
#define buz 11
#define ldr A5
#define led 10
#define tmp A4
int seg[7];
int numcars=4;
int irread1;
int irread2;
int ldrread;
float tempread;
void setup() {
  Serial.begin(9600);
  motor.attach(9);
//  pinMode(a,OUTPUT);
//  pinMode(b,OUTPUT);
//  pinMode(c,OUTPUT);
//  pinMode(d,OUTPUT);
//  pinMode(e,OUTPUT);
//  pinMode(f,OUTPUT);
//  pinMode(g,OUTPUT);
for (int i= 8; i>=2;i--){
  seg[8-i] =i;
  pinMode(i,OUTPUT);
}
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ldr,INPUT);
  pinMode(buz,OUTPUT);
  pinMode(tmp,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
//ir read 
irread1 = digitalRead(ir1);
irread2 = digitalRead(ir2);

//   start light due to ldr 
ldrread =  analogRead(ldr);
//ldrread = map(ldrread,1000,174,0,255);

if(ldrread<=1000){
  digitalWrite(led,LOW);
 
  }
  
else{
  digitalWrite(led,HIGH);
 
  }
  // end light due to ldr
//  temp
tempread =analogRead(tmp);
tempread = (tempread *(5.0/1023.0));
tempread = (tempread /0.01);
tempread =tempread -35;
Serial.println(tempread);
if(tempread>=40)digitalWrite(buz,HIGH);
else(digitalWrite(buz,LOW));

//gate open in case of decrease number of available places
if(numcars!=0){
if(irread1==0){
  for(int i = 90;i>0;i=i-1){
      motor.write(i);
      delay(12);
      }
  while(irread1 == 0){
    irread1 = digitalRead(ir1);
    irread2 = digitalRead(ir2);
    }
    
  if(irread2==0){
    numcars--;
    for(int i = 0;i<=90;i=i+1){
      motor.write(i);
      delay(12);
        while(irread2 == 0){
    irread1 = digitalRead(ir1);
    irread2 = digitalRead(ir2);
    }
      
      }
         irread1 = digitalRead(ir1);
   irread2 = digitalRead(ir2); 
    }
  else if (  irread1==1 && irread2==1){
    for(int i = 0;i<=90;i=i+1){
      motor.write(i);
      delay(12);
      }
    }
  }
}
// gate open in case of increase number of available places
if(irread2==0){
  for(int i = 90;i>0;i=i-1){
      motor.write(i);
      delay(12);
      }
  while(irread2 == 0){
    irread1 = digitalRead(ir1);
    irread2 = digitalRead(ir2);
    }
   irread1 = digitalRead(ir1);
   irread2 = digitalRead(ir2);  
  if(irread1==0){
    numcars++;
    for(int i = 0;i<90;i=i+1){
      motor.write(i);
      delay(12);
        while(irread1 == 0){
    irread1 = digitalRead(ir1);
    irread2 = digitalRead(ir2);
    }
      }
    }
  else if (  irread1==1 && irread2==1){
    for(int i = 0;i<90;i=i+1){
      motor.write(i);
      delay(12);
      }
    }
  }

// number of cars 
// number 4
if(numcars==4){
//  digitalWrite(f,HIGH);
//  digitalWrite(g,HIGH);
//  digitalWrite(b,HIGH);
//  digitalWrite(c,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(e,LOW);
//  digitalWrite(d,LOW);
  for (int i=0 ;i<7;i++){
  if(i==4 || i== 5 ||i==1 ||i==0)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  }

  
//  number 3
if(numcars==3){
//  digitalWrite(a,HIGH);
//  digitalWrite(g,HIGH);
//  digitalWrite(b,HIGH);
//  digitalWrite(c,HIGH);
//  digitalWrite(d,HIGH);
//  digitalWrite(e,LOW);
//  digitalWrite(f,LOW);
  for (int i=0 ;i<7;i++){
  if(i==4 || i== 5 ||i==6 ||i==3 ||i==0)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  }

  

// number 2
if(numcars==2){
//  digitalWrite(d,HIGH);
//  digitalWrite(g,HIGH);
//  digitalWrite(b,HIGH);
//  digitalWrite(e,HIGH);
//  digitalWrite(a,HIGH);
//  digitalWrite(f,LOW);
//  digitalWrite(c,LOW);
  for (int i=0 ;i<7;i++){
  if(i==0 || i== 5 ||i==6 ||i==3 ||i==2)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  }

  
//number 1
if(numcars==1){
//  digitalWrite(f,LOW);
//  digitalWrite(g,LOW);
//  digitalWrite(b,HIGH);
//  digitalWrite(c,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(e,LOW);
//  digitalWrite(d,LOW);
  for (int i=0 ;i<7;i++){
  if(i==4 || i== 5 )digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  }

  
//full
if(numcars == 0){
//    digitalWrite(a,HIGH);
//  digitalWrite(f,HIGH);
//  digitalWrite(e,HIGH);
//  digitalWrite(g,HIGH);
//  digitalWrite(b,LOW);
//  digitalWrite(c,LOW);
//  digitalWrite(d,LOW);
//  delay(500);
//  digitalWrite(f,HIGH);
//  digitalWrite(b,HIGH);
//  digitalWrite(c,HIGH);
//  digitalWrite(e,HIGH);
//  digitalWrite(d,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(g,LOW);
//
//  delay(500);
//  digitalWrite(f,HIGH);
//  digitalWrite(b,HIGH);
//  digitalWrite(e,HIGH);
//  digitalWrite(c,HIGH);
//  digitalWrite(a,LOW);
//  digitalWrite(g,LOW);
//  digitalWrite(d,LOW);
//  delay(500);
for (int i=0 ;i<7;i++){
  if( i==6 ||i==1 ||i==0 ||i==2)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  
for (int i=0 ;i<7;i++){
  if(i==4 || i== 5 ||i==1 ||i==3 ||i==2)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  
for (int i=0 ;i<7;i++){
  if(i==4 || i== 5 ||i==1 ||i==2)digitalWrite(seg[i],HIGH);
  else(digitalWrite(seg[i],LOW));
  }
 delay(500);
  }



  
}
