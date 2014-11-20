#include <Arduino.h>
#include "Tanks.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>

#include <lcd_image.h>    // U of A Utils 

// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card
#define TFT_CS   6  // Chip select line for TFT display
#define TFT_DC   7  // Data/command line for TFT
#define TFT_RST  8  // Reset line for TFT (or connect to +5V)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Please note the image has to be uploaded to the SD card.
lcd_image_t map_image = { "Mountain.lcd", 128, 160 };
int TerrainH = 30;

void Draw_Map(){

  tft.initR(INITR_REDTAB);

  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) 
    {
    Serial.println("failed!");
    return;
    }
  Serial.println("OK!");

  // Draws the background image
  lcd_image_draw(&map_image, &tft, 0, 0, 0, 0, 128, 160);

  // Draws the ground, AKA a big green rectange on the bottom.
  tft.fillRect(0,0,TerrainH,160,0x0620);
}

int Tank1_x = 20;

void Draw_Tanks()
{
  tft.fillRect(TerrainH,Tank1_x,6,10,0x001F);
  tft.fillRect(TerrainH+4,(Tank1_x+10),2,6,0x001F);
}
