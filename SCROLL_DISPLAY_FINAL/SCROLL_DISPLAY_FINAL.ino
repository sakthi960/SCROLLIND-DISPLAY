#include <Adafruit_GFX.h>        // Core graphics library
#include <Adafruit_NeoMatrix.h>  // NeoPixel matrix library
#include <Adafruit_NeoPixel.h>   // NeoPixel library

#define PIN 5  // The pin connected to the data input of the NeoPixel matrix

// Matrix size (change according to your matrix specifications)
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 7

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, PIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                                               NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {

  matrix.Color(0, 255, 0),  // GREEN

};

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(200);  // Adjust brightness (0-255)
  matrix.setTextColor(colors[0]);
}

void loop() {
  static uint8_t colorIndex = 0;
  static int16_t x = matrix.width();
  static int8_t pass = 0;

  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("DEPARTMENT OF ECE"));

  if (--x < -100) {  // Change -100 to the width of your text (e.g., 8 pixels per character)
    x = matrix.width();
    if (++pass >= 1) pass = 0;
    matrix.setTextColor(colors[pass]);
  }

  matrix.show();
  delay(100);
}
