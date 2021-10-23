#include <Adafruit_NeoPixel.h>
#define PIN        2
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 20

void setup() {
  Serial.begin(115200);
  pixels.begin();
}

int r, g, b;
int nor, nog, nob;

void loop() {
  int ner = random(255);
  int neg = random(255);
  int neb = random(255);
  for (int i = 1; i <= 10; i ++) {
    nor = r + (((ner - r ) / 10 ) * i);
    nog = g + (((neg - g ) / 10 ) * i);
    nob = b + (((neb - b ) / 10 ) * i);
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(nor,nog,nob));
    pixels.show();
    Serial.printf("R:%d,G:%d,B:%d\n",nor,nog,nob);
    delay(DELAYVAL);
  }
  r = nor;
  g = nog;
  b = nob;
}
