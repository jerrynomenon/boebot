// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo_right;  // create servo object to control a servo 
Servo myservo_left;   // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo_left.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo_right.attach(8);
} 
 
 
void loop() 
{ 
  int s = 90;
  myservo_left.write(91);
  myservo_right.write(91);
  
//  for(int i=1;i<9;i++) {
//     int t =  s+(i*10);
//     myservo_left.write(t);
//     myservo_right.write(t);
//     delay(10000);  
//  }
    
  
  
//  myservo_left.write(1000);          // move clockwise
//  delay(1000);
//  myservo_left.write(1500);          // move stop
//  delay(1000);
//  myservo_left.write(2000);          // move anticlockwise
//  delay(1000);
//  myservo_left.write(1500);          // move stop
//  delay(1000);

 forward();
  //backward();
  //stop_motion();
  
} 


void forward(){
  for(int i=0;i<10;i++)
  {
  myservo_left.write(2000);          
  myservo_right.write(1000);
  delay(250);
  }
}

void backward(){
  for(int i=0;i<10;i++)
  {
  myservo_left.write(1000);          
  myservo_right.write(2000);
  delay(250);
  }
}

void stop_motion(){
  myservo_left.write(1500);          
  myservo_right.write(1500);
}
