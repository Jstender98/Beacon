// SPDX-FileCopyrightText: 2011 Limor Fried/ladyada for Adafruit Industries
//
// SPDX-License-Identifier: MIT

// thermistor-1.ino Simple test program for a thermistor for Adafruit Learning System
// https://learn.adafruit.com/thermistor/using-a-thermistor by Limor Fried, Adafruit Industries
// MIT License - please keep attribution and consider buying parts from Adafruit
  
// What pin to connect the sensor to
// #define PHOTODIODEPIN A0
#define THERMISTORPIN A0
#define THERMISTORNOMINAL 100000
#define TEMPERATURENOMINAL 25
#define NUMSAMPLES 5
#define BCOEFFICIENT 3950
#define SERIESRESISTOR 100000

int samples[NUMSAMPLES];

void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  uint8_t i;
  float average;

  //take N samples w/ slight delay
  for (i = 0; i < NUMSAMPLES; i++) {
    samples[i] = analogRead(THERMISTORPIN);
    delay(10);
  }

  //average samples
  average = 0;
  for(i = 0; i < NUMSAMPLES; i++) {
    average += samples[i];
  }
  average /= NUMSAMPLES;

  Serial.print("Analog reading avg\t");
  Serial.println(average);
  
  // convert the value to resistance
  average = (1023 / average)  - 1;     // (1023/ADC - 1) 
  average = SERIESRESISTOR / average;  // 4.6k / (1023/ADC - 1)
  Serial.print("Thermistor resistance "); 
  Serial.println(average);

  float steinhart;
  steinhart = average / THERMISTORNOMINAL;
  steinhart = log(steinhart);
  steinhart /= BCOEFFICIENT;
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;

  Serial.print("Temperature ");
  Serial.print(steinhart);
  Serial.println(" *C");

  delay(2000);
 
}
