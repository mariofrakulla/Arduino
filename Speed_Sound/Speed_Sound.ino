/*Sample Script for measuring Speed of Sound, using an Ultrasonic sensor
 * Author: Mario Frakulla
 * Date Created: August 2017
 */
int TrigPin = 13;
int EchoPin = 11;
float pingTime;
float distance = 24; // double the distance (cm)
float speedOfSound;
float sumSpeed = 0; 

void setup() {

Serial.begin(9600);
pinMode(TrigPin, OUTPUT); //Giving values HIGH/LOW to the Trig Pin
pinMode (EchoPin, INPUT); //Reading time value from Echo Pin
}

void loop() {

for( int i = 1; i <= 12; i++){
  
digitalWrite(TrigPin, LOW); 
delayMicroseconds(2000); //Pause to let signal settle
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); //Pause with trigger pin HIGH
digitalWrite(TrigPin, LOW);//Finnish trigger pulse

pingTime = pulseIn(EchoPin, HIGH); //Measure time in MICROSECONDS
speedOfSound = (distance/pingTime)*10000; // meters/second
sumSpeed = sumSpeed + speedOfSound;
Serial.println(speedOfSound); 
delay(500);
}
Serial.println( "The avergae speed of sound for this round was: "); 
Serial.println(sumSpeed/12); 
}
