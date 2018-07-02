/*Mapping Potentiometer values to servo rotation values
 * Test for DSSL project
 * Author: Mario Frakulla
 * Date Created: January 2018
 */



int escPin = 9;
int potPin = A0; 
int potVal;
int escVal;
int potPinTwo = A1;
int potValTwo;
int servoVal;
int servoPin = 10;  

void setup() {
 Serial.begin(9600);
 pinMode(escPin, OUTPUT);
 pinMode(potPin, INPUT);
 pinMode(potPinTwo, INPUT);
 pinMode(potValTwo, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  escVal = map(potVal, 0, 1023, 163, 300);
  potValTwo = analogRead(potPinTwo); 
  servoVal = map(potValTwo, 0, 1023,0, 180);
  analogWrite(servoPin, servoVal);
  Serial.print(escVal);
  Serial.print("\n");
  analogWrite(escPin, escVal);
  delay(100);
}
