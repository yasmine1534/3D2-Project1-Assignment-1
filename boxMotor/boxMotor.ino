/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 1

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 90);      // scale it to use it with the servo (value between 0 and 90), changed the degrees to 90
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
  Serial.println(val);                 //prints val

  if ((val < 36) && (val >= 0)) {
    //show red when it's locked
    strip.setPixelColor(0, 255, 0, 0);
    strip.show();
  } else if ((val >= 36) && (val < 54)) {
    //show yellow when it's midway
    strip.setPixelColor(0, 255, 100 , 0);
    strip.show();
  } else if ((val >= 54) && (val < 90)) {
    //show green when it's unlocked
    strip.setPixelColor(0, 0 , 255, 0);
    strip.show();
  }
}
