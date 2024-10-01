#include <ESP32Servo.h>


int sensorPin = 34; 
int threshold = 2000; 
int servo1Pin = 18;   
int servo2Pin = 19; 

Servo servo1;
Servo servo2;

String state;
String action;

void setup() {
  pinMode(sensorPin, INPUT); 
  Serial.begin(9600);
  
 
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  
  
  servo1.write(0);  
  servo2.write(0);  
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  
  if (sensorValue < threshold) {
    state = "cool";
    action = "servo motor on"; 
    servo1.write(180);   
    servo2.write(180);     
  } else {
    state = "dry";
    action = "servo motor off"; 
    servo1.write(0);      
    servo2.write(0);   
  }

  // Output formatted data
  Serial.print("#"); // # - SOF
  Serial.print(","); // , - Separator
  Serial.print(sensorValue); // value1
  Serial.print(","); // , - Separator
  Serial.print(state); // value2
  Serial.print(","); // , - Separator
  Serial.print(action); // value3
  Serial.print(",");
  Serial.println("~"); // ~ - EOF

  delay(2000);
}
