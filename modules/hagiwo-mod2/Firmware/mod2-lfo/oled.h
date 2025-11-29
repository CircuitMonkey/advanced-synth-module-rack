#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

#define SDA 12
#define SCL 13

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // 0x3C for 128x32

#define NUMFLAKES 10  // Number of snowflakes in the animation example

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16


class OLED {
  public:
    OLED();
    Adafruit_SSD1306 display;
    void begin();
    void loop();

  private:
    void adaSplashAddOns();    // Additional text for Ada logo splash.
    void testdrawline();       // Draw many lines
    void testdrawrect();       // Draw rectangles (outlines)
    void testfillrect();       // Draw rectangles (filled)
    void testdrawcircle();     // Draw circles (outlines)
    void testfillcircle();     // Draw circles (filled)
    void testdrawroundrect();  // Draw rounded rectangles (outlines)
    void testfillroundrect();  // Draw rounded rectangles (filled)
    void testdrawtriangle();   // Draw triangles (outlines)
    void testfilltriangle();   // Draw triangles (filled)
    void testdrawchar();       // Draw characters of the default font
    void testdrawstyles();     // Draw 'stylized' characters
    void testscrolltext();     // Draw scrolling text
    void testdrawbitmap();     // Draw a small bitmap image
    void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h);
};

const unsigned char PROGMEM ada_logo_bmp[] = 
    { 0b00000000, 0b11000000,
      0b00000001, 0b11000000,
      0b00000001, 0b11000000,
      0b00000011, 0b11100000,
      0b11110011, 0b11100000,
      0b11111110, 0b11111000,
      0b01111110, 0b11111111,
      0b00110011, 0b10011111,
      0b00011111, 0b11111100,
      0b00001101, 0b01110000,
      0b00011011, 0b10100000,
      0b00111111, 0b11100000,
      0b00111111, 0b11110000,
      0b01111100, 0b11110000,
      0b01110000, 0b01110000,
      0b00000000, 0b00110000 };

#endif