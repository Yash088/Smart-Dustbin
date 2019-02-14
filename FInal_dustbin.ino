#include<Wire.h>
#include<Servo.h>

long duration;
long duration1;
int dist,dist1;
Servo me;
void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);//Echo pin
pinMode(2,OUTPUT);//Trig Pin
pinMode(4,INPUT);//echo pin1
pinMode(5,OUTPUT);//trig pin1
Serial.begin(9600);
me.attach(9);
me.write(0);         //close dustbin cap on power on
delay(1000);
me.detach();
}
void loop() {
digitalWrite(2,HIGH);//trig pin high
delayMicroseconds(10);
digitalWrite(2,LOW);//trig pin low
duration=pulseIn(3,HIGH);//echo pin high
dist=duration*0.034/2;
Serial.print("Distance");
Serial.println(dist);
digitalWrite(5,HIGH);
delayMicroseconds(10);
digitalWrite(5,LOW);
duration1=pulseIn(4,HIGH);
dist1=duration1*0.034/2;
Serial.print("Distance");
Serial.println(dist1);


if ( dist<40 )//in cm 
{
 //if hand on the distance 10...50 cm
 me.attach(9);
  delay(1);
 me.write(90);  
 delay(6000);       //wait 5 seconds
 me.write(0);    
 delay(1000);
 me.detach();      
}
if(dist1<5) //in cm
{
  Serial.println("code is ok");
  tone(7,1000);
  delay(1000);
  noTone(7);
}

}
