/*
  Author: Rodskin 
  twitter: @rodskin
  
  This program and Arduino project was made after seeing "Shoot, la photographie existentielle" a photography exposition.
  My girlfriend loved this so much, that I wanted to recreate it for her birthday.
  
  Feel free to modify, and reproduce
  
  Special thanks to @semageek who owns http://semageek.com (Arduino e-shopping website) and who helped me in my work.
*/

// these constants won't change:
const int led = 13;  // led connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 50;  // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
int oldPotiValue=0;//stores the old potentiometer value, to see changes
void loop(){
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    Serial.println(1); // send 1 on serial to take a picture
    
    if(Serial.available() > 0){//if serial is sending
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    } else {
      digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
    }
  }
  
  delay(2000);  // delay to avoid overloading the serial port buffer
}
