#include <Servo.h> 
Servo myservo_right;  // create servo object to control a servo 
Servo myservo_left;   // a maximum of eight servo objects can be created 
 
int pos = 0; 

const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  myservo_left.attach(4);  // attaches the servo on pin 9 to the servo object 
  myservo_right.attach(2);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    Serial.print(incomingByte);
    if (incomingByte == 'H') {
       //Serial.print('H');
       forward();
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
       //Serial.print('L');
       backward();
    }

    if (incomingByte == 'X') {
       //Serial.print('X');
       turnleft();
    }

    if (incomingByte == 'Y') {
       //Serial.print('Y');
       turnright();
    }
  }
//  else {
//    Serial.print('N');
//  }
}

void forward(){
  for(int i=0;i<10;i++)
  {
  myservo_left.write(2000);          
  myservo_right.write(1000);
  delay(50);
  }
}

void backward(){
  for(int i=0;i<10;i++)
  {
  myservo_left.write(1000);          
  myservo_right.write(2000);
  delay(50);
  }
}

void turnleft() {
  for(int i=0;i<10;i++)
  {
  myservo_left.write(1450);          
  myservo_right.write(1000);
  delay(50);
  }
}

void turnright() {
  for(int i=0;i<10;i++)
  {
  myservo_left.write(2000);          
  myservo_right.write(1550);
  delay(50);
  }
}

