int RedPin = 11;
int BluePin = 6;
int GreenPin = 10;
int brightnessRed = 1;
int brightnessBlue =  1;
int brightnessGreen = 1; 
int delayValue = 100;



void setup() {

  Serial.begin(9600); 
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);


}

void loop() {

while(brightnessRed <= 225 ){
  delay(delayValue);
  analogWrite(RedPin, brightnessRed);
  analogWrite(GreenPin, brightnessGreen);
  analogWrite(BluePin,brightnessBlue);
  delay(delayValue);
  
  while(brightnessBlue <= 225){
  delay(delayValue);
  analogWrite(RedPin, brightnessRed);
  analogWrite(GreenPin, brightnessGreen);
  analogWrite(BluePin,brightnessBlue);
  delay(delayValue);
  
   while(brightnessGreen <= 225){
  delay(delayValue);
  analogWrite(RedPin, brightnessRed);
  analogWrite(GreenPin, brightnessGreen);
  analogWrite(BluePin,brightnessBlue);
  delay(delayValue);
  brightnessGreen += 15; 
    }
    brightnessBlue += 15;
  }
  brightnessRed += 15;
}


}
