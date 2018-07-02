/*Script for measuring distance using an Ultrasonic Sensor*
 Author: Mario Frakulla
 DateCreated: August 2017*/


int TrigPin = 13;
int EchoPin = 11;
int speedSound = 343; //m/s 
float timeVal; 
float distance;

void setup() {

Serial.begin(9600); 
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
}

void loop() {
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(TrigPin, LOW); 

timeVal = pulseIn(EchoPin, HIGH);
distance = (timeVal * speedSound)/1000000; // result in meters

Serial.println(distance/2);
delay(500); 
}
