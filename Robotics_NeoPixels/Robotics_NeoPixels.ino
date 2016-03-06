#include <Adafruit_NeoPixel.h>

#define NUM_PIXELS 180
#define PIN 6
#define WAIT 50

uint32_t orange, purple, green;
int brightness = 100;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  orange = strip.Color(255,128,0);
  purple = strip.Color(128,0,255);
  green = strip.Color(0,255,0);

  strip.clear();
  strip.show();
}

void loop() 
{
  sequence1(3);
}

void sequence1(int times)
{
  boolean complete;
  int start = 0;
  for(int count = 0; count < times; count++)
  {
    complete = false;
    while(!complete)
    {
      for(int i = start; i < NUM_PIXELS; i+=3)
      {
        strip.setPixelColor(i%start, purple);
        strip.setPixelColor(i%start+1, orange);
        strip.setPixelColor(i%start+2, green);
        delay(WAIT);
      }
      start++;
      if(start > 180)
        complete = true;
    }
  }
}

