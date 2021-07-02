/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/WindyCity_IOT/Labs/Lab6/src/Lab6.ino"

#include "oled-wing-adafruit.h"
void setup();
void loop();
#line 3 "d:/WindyCity_IOT/Labs/Lab6/src/Lab6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;


// variables
uint16_t reading;
double voltage;
double temperature;
  

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(A4, INPUT);
  

  // init display values
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // read temp
  reading = analogRead(A4);
  voltage = (reading * 3.3) / 4095.0;
  temperature = (voltage - 0.5) * 100;

  // print temp
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Celsius: ");
  display.print(temperature);
  display.println(" C");
  display.println();
  display.print("Fahrenheit: ");
  display.print((temperature*9/5)+32);
  display.println(" F ");
  display.display();

  delay(300);
}