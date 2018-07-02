/* 2 LED EXAMPLE SCRIPT
 *  Author: Mario Frakulla
 *  Date Created: September 2017
 */

int redLED = 9;
int blueLED = 10;
int redTimeOn = 300;
int redTimeOff = 300;
int blueTimeOn = 300;
int blueTimeOff = 300;
int numberRedIterations;
int numberBlueIterations;

void setup() {

pinMode(redLED,OUTPUT);
pinMode(blueLED, OUTPUT);
Serial.begin(9600);
}

void loop() {
    Serial.println("How many times do you want the Red LED to blink?");
  while(Serial.available() == 0){ } //pause program until a int is entered;
  numberRedIterations = Serial.parseInt();
  Serial.println("How many times do you want the Blue LED to blink?");
  while(Serial.available() == 0){ }
  numberBlueIterations = Serial.parseInt();

 Serial.println("Red LED");
for(int i = 1; i <= numberRedIterations; i++){
  Serial.println(i);
analogWrite(redLED, 51);
delay(redTimeOn);
analogWrite(redLED, 0);
delay(redTimeOff);
}

Serial.println("Blue LED");
for(int j = 1; j<=numberBlueIterations; j++){
  Serial.println(j);
analogWrite(blueLED, 51);
delay(blueTimeOn);
analogWrite(blueLED,0);
delay(blueTimeOff);
}

}
