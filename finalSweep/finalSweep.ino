#include <Servo.h>

Servo servoMotor;       // creates an instance of the servo object to control a servo
const int servoPin = 9;       // Control pin for servo motor
const int buttonPin = 4;

int pos;

void setup() {
  Serial.begin(9600);       // initialize serial communications
  servoMotor.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT); // declares buttonPin as input
}

void loop() {
  int buttonPressed = digitalRead(buttonPin);  // read input value

  Serial.println("BUTTON STATE SHOULD BE LOW HERE");
  Serial.println(buttonPressed);

  if (buttonPressed == HIGH) {

    Serial.println("Button is clicked");
    Serial.println(buttonPressed);
    
        pos = 0;
        servoMotor.write(pos);
        delay(500);
        pos = 90;
        servoMotor.write(pos);
        delay(500);

    // delay(500)
    if (pos == 90) exit(1);
  }
}
