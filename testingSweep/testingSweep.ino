#include <Servo.h>

Servo servoMotor;       // creates an instance of the servo object to control a servo
const int servoPin = 9;       // Control pin for servo motor

//int servoSpeed = 175;   // set a variable for the speed of the continuous servo, can be sped up or slowed down
int pos;

void setup() {
  Serial.begin(9600);       // initialize serial communications
  servoMotor.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    Serial.println("HIT BALL");

    for (pos = 0; pos <= 90; pos += 90) { // goes from 0 degrees to 90 degrees 
      Serial.println(pos);                // Checks position in console
      servoMotor.write(pos);              // tell servo to go to position 
      delay(500);
    }
    delay(10000);
}
