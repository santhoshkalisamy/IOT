/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int sensor=A1;
float tempc;  
float tempf;  
float vout; 

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);

  showWelcomeMessage();  

  pinMode(sensor,INPUT);

}

void loop() {
vout=analogRead(sensor);
Serial.print("Analog Value = ");
Serial.print(vout);
Serial.println();
vout=(vout*5000)/1023;
tempc=vout/10; // Storing value in Degree Celsius
tempf=(tempc*1.8)+32; // Converting to Fahrenheit 
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println();
Serial.print("in Fahrenheit=");
Serial.print("\t");
Serial.print(tempf);
Serial.println();
showTemp(tempf, tempc);
delay(1000); //Delay of 1 second for ease of viewing 
}

void showTemp(int tempf, int tempc) {

  display.clearDisplay();
  display.setTextSize(2); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(40, 0);
  display.println(F("Temp"));
  display.setCursor(0, 20);
  display.print(F("F: "));
  display.println(tempf);
  display.setCursor(0, 40);
  display.print(F("C: "));
  display.println(tempc);

  display.display();    // Show initial text
}

void showWelcomeMessage(void) {
    delay(2000);

  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Welcome"));
  display.setCursor(10, 20);
  display.println(F("Back"));
  display.setCursor(10, 40);
  display.println(F("To"));

  display.display();      // Show initial text
  delay(5000);

  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Internet"));
  display.setCursor(40, 20);
  display.println(F("Of"));
  display.setCursor(30, 40);
  display.println(F("Tech"));

  display.display();      // Show initial text
  delay(2000);
}
