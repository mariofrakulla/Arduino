
/*Create a mapping between distance measured by HC-SR04 Ultrasonic Sensor and blinking rate of two LEDs
 * Author: Mario Frakulla
 * Date Created: August 2017
 */
int EchoPin = 11;
int TrigPin = 13;
int BlueLED = 6;
int RedLED = 5;
int delayRedLED;
float timePulse;
int speedOfSound;
int distancePulse;

void setup() {

Serial.begin(9600);
pinMode(BlueLED, OUTPUT);
pinMode(RedLED, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(TrigPin, OUTPUT); 

}

void loop() {

distancePulse = DistanceCal();
printDistance(distancePulse);
BlinkingRate(distancePulse);
}

int DistanceCal(){
float distance;
digitalWrite(TrigPin, LOW);
delayMicroseconds(2000);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(20);
digitalWrite(TrigPin,LOW);
timePulse = pulseIn(EchoPin,HIGH);
distance = timePulse * speedOfSound/1000000;
distance = distance/2;
delay(50); 
return distance; 
}

void printDistance(int diVal){
  Serial.println(diVal); 
  delay(50);
}
void BlinkingRate(int dVal){ 

if(dVal >= 0.05 && dVal<= 0.2){
  digitalWrite(RedLED,HIGH);
  delay(6*dVal - 200);
  digitalWrite(BlueLED,LOW);
  delay(6*dVal - 200);
}if(dVal > 0.2 && dVal <= 0.35){
  digitalWrite(RedLED,HIGH);
  delay(6*dVal - 1100);
  digitalWrite(BlueLED,LOW);
  delay(6*dVal - 1100);
}
}

