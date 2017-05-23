#include <Servo.h>
#include "pitches.h"
#include <time.h>
#include <stdlib.h>

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,NOTE_C5, NOTE_G4,
NOTE_F4, NOTE_E4, NOTE_D4,NOTE_C5, NOTE_G4, NOTE_F4,NOTE_E4 ,NOTE_F4, NOTE_D4 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2,2,12,12,12,2,4,12,12,12,2,4,12,12,12,2 
};
  
Servo myservo_left;
Servo myservo_right;
int state = 0; // 0 no collision detected move forward 1 collision detected stop
              // and start turning
const int pingPin = 11; // sonar at pin 11

void setup(){
  myservo_left.attach(9); //connect to pin 9
  Serial.begin(9600);
  myservo_right.attach(8); // connect to pin 8 
    for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1500/noteDurations[thisNote];
    tone(12, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    //stop the tone playing:
    noTone(12);
    
  }
  
}

void loop(){
 pinMode(pingPin, OUTPUT); // pin is now outputting a pulse
 digitalWrite(pingPin,LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin,HIGH);
 delayMicroseconds(5); // 5 second pulse
 digitalWrite(pingPin,LOW);
 
 pinMode(pingPin,INPUT); // pin is now recieving
 long duration = pulseIn(pingPin, HIGH);
 
 long range = microsecondsToCentimeters(duration);
 Serial.print(range);
 Serial.print("cm");
 Serial.println();
 delay(100);
if (range < 20){
   int noteDuration = 1500/noteDurations[1];
   tone(12, NOTE_A7, noteDuration);
 }
 else if(range > 30){
   int noteDuration = 1500/noteDurations[1];
   tone(12, NOTE_G1 ,noteDuration);
 }
 else{
    int noteDuration = 1500/noteDurations[1];
   tone(12, NOTE_A4 , noteDuration);
 }
//myservo_left.write(1000);
//myservo_right.write(1000);
 state = moving(state,range);
  
}

int moving(int state, long range){
 if(range < 20) state = 1;
 else state = 0 ;
 if( state == 0){ // move forward
   myservo_right.write(1000); //CW
   myservo_left.write(2000);
 }
  else{
    Serial.println("Collision Detected!");
    srand((int)range*10000);
    state = turnAround(); // turns the bot 180 degrees
  } 
 return state;
}


int turnAround(){
   myservo_right.write(1000);
   myservo_left.write(1000);
   int r = rand()%200 - 100;
   delay(1200 + r);
   myservo_right.write(1500);
   myservo_left.write(1500);
   return 0;
   
}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  Serial.println(microseconds);
  return microseconds / 29 / 2;
}
