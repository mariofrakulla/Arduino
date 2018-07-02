/*Controlling Blinking rate of LED using a potentiometer
 * Author: Mario Frakulla
 * Date Created: September 2017
 */


int LEDPin = 9;
int PotPin = A0; //Pin that will read values of the Potentiometer 
float BlinkValue;
int ReadValue;

void setup() {

  Serial.begin(9600); 
  pinMode(LEDPin, OUTPUT);
  pinMode(PotPin, INPUT);
  
}

void loop() {

ReadValue = analogRead(PotPin); 
BlinkValue = (((0.99/1023.0) * ReadValue) + 0.01)*1000;
digitalWrite(LEDPin,HIGH);
delay(BlinkValue);
digitalWrite(LEDPin,LOW);
delay(BlinkValue);
Serial.println("The LED blinks once in");
Serial.println(BlinkValue);
}
