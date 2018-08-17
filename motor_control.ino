#include <Wire.h>
#include "Adafruit_TCS34725.h"

 const int relay_pin = 8;
  /* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  pinMode(relay_pin, OUTPUT);
  Serial.begin(9600);
  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    //Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void loop() {
    String com = Serial.readString();
    uint16_t r, g, b, cor;
  if (com == "r"){
    digitalWrite(relay_pin, HIGH);
          delay(7000);
    digitalWrite(relay_pin, LOW);
        delay(4000);
        //Serial.print("parou: ");
          tcs.getRawData(&r, &g, &b, &cor);
          //Serial.print("Cor: "); Serial.print(cor, DEC);Serial.println();

        if ((cor > 3000) && (cor < 5000)){
          Serial.println("Blue");
        } else if ((cor > 6000) && (cor < 7050)) {
          Serial.println("Green");
        } else if ((cor > 7051) && (cor < 7500)) {
          Serial.println("Cyan");
        } else if ((cor > 8000) && (cor < 8800)){
          Serial.println("Red");
        } else if ((cor > 8900) && (cor < 10000)) {
          Serial.println("Yellow");
        } else if ((cor > 10500) && (cor < 15000)) {
          Serial.println("Magenta");
        } else {
          Serial.println("indefinido");
        }
 
  } else if (com == "s"){
    digitalWrite(relay_pin, LOW);
  }

}
