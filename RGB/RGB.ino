
/*Controlling RGD LED 
 * Author: Mario Frakulla
 * Date Created: August 2017
 */
int RedPin = 11 ;
int BluePin = 6 ;
int GreenPin = 10 ;
int brightness = 255 ;
String choice; 

void setup() {
  Serial.begin(9600);
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void loop() {

Serial.println("Please input your color choice (green, blue, red) ");

while(Serial.available() == 0){ } 
choice = Serial.readString();

if(choice == "blue"){ 

analogWrite(RedPin, 0);
analogWrite(BluePin, brightness);
analogWrite(GreenPin, 0);
  
}if(choice == "red"){
analogWrite(BluePin, 0);
analogWrite(GreenPin, 0);
analogWrite(RedPin, brightness);

}if(choice == "green"){ 
analogWrite(RedPin, 0);
analogWrite(BluePin, 0);
analogWrite(GreenPin, brightness);

}if(choice != "blue" && choice != "red" && choice != "green"){ 
  Serial.println();
  Serial.println("You have not entered a valid color! Please, enter red, green, or blue");
  Serial.println(); 
}

}
