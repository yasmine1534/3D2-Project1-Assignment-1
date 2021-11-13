// A basic everyday NeoPixel strip test program.

/* Strandtest example code modified Jan 2021 Doug Whitton
    This example is a barebones version of the Adafruit sample code
    It lights up a strip of 2 neopixels
    The colour is random
    Thee colorWipe method is called from the loop()
    strip is a variable name for an Adafruit_NeoPixel object

*/
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 3

int wait = 2000;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // Fill along the length of the strip in various colors...
  //colorWipe(strip.Color(random(255),random(255),random(255)), 500);
  //  colorWipe(strip.Color(random(255),random(255),random(255)), 500);
  //colorWipe(strip.Color(random(255),random(255),random(255)), 500);

  //  colorWipe(strip.Color(random(255),0,0), 500);
  // colorWipe(strip.Color(0,255,0), 500);


  //Monotone
  strip.setPixelColor(0, 255, 0, 120);
  strip.show();                          //  Update strip to match
  delay(wait);
  strip.setPixelColor(1, 255, 100, 120);
  strip.show();                          //  Update strip to match
  delay(wait);
  strip.setPixelColor(2, 255, 255, 255);
  strip.show();                          //  Update strip to match
  delay(wait);
  colorWipe(strip.Color(0, 0, 0), 500);
  strip.show();
  delay(wait);
}


// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    wait = 200;
    strip.setPixelColor(i, color);  //  Set pixel's color (in RAM)
    //    strip.setPixelColor(i, 0);

    //Not so random testing
    //    strip.setPixelColor(0, random(255),0,0);
    //    strip.setPixelColor(1, (random(255)),random(255),0);
    //    strip.setPixelColor(2, (random(255)),random(255),random(255));

    //Traffic light
    //    red light
    //    strip.setPixelColor(0, 255 ,0,0);
    //    strip.show();                          //  Update strip to match
    //    delay(wait);
    //    yellow light
    //    strip.setPixelColor(1, 255, 100 ,0);
    //    strip.show();                          //  Update strip to match
    //    delay(wait);
    //    green light
    //    strip.setPixelColor(2, 0, 255 ,0);

    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
