// SPDX-FileCopyrightText: 2011 Limor Fried/ladyada for Adafruit Industries
//
// SPDX-License-Identifier: MIT

// thermistor-1.ino Simple test program for a thermistor for Adafruit Learning System
// https://learn.adafruit.com/thermistor/using-a-thermistor by Limor Fried, Adafruit Industries
// MIT License - please keep attribution and consider buying parts from Adafruit
  
// What pin to connect the sensor to
// #define PHOTODIODEPIN A0
#define T0 A0
#define T1 A1
#define T2 A2

#define P8 A3
#define P9 A4
#define P10 A5

#define NUMSAMPLES 5
#define THERMSERIESRESISTOR 100000
#define PHOTOSERIESRESISTOR 10000

int samples0[NUMSAMPLES];
int samples1[NUMSAMPLES];
int samples2[NUMSAMPLES];

int samples8[NUMSAMPLES];
int samples9[NUMSAMPLES];
int samples10[NUMSAMPLES];

void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  uint8_t i;
  float av0;
  float av1;
  float av2;
  float av8;
  float av9;
  float av10;

  //take N samples w/ slight delay
  for (i = 0; i < NUMSAMPLES; i++) {
    samples0[i] = analogRead(T0);
    samples1[i] = analogRead(T1);
    samples2[i] = analogRead(T2);

    samples8[i] = analogRead(P8);
    samples9[i] = analogRead(P9);
    samples10[i] = analogRead(P10);
  }

  //average samples
  av0 = 0;
  av1 = 0;
  av2 = 0;
  
  av8 = 0;
  av9 = 0;
  av10 = 0;

  for(i = 0; i < NUMSAMPLES; i++) {
    av0 += samples0[i] / NUMSAMPLES;
    av1 += samples1[i] / NUMSAMPLES;
    av2 += samples2[i] / NUMSAMPLES;

    av8 += samples8[i] / NUMSAMPLES;
    av9 += samples9[i] / NUMSAMPLES;
    av10 += samples10[i] / NUMSAMPLES;
  }

  av0 = (1023 / av0)  - 1;
  av0 = THERMSERIESRESISTOR / av0;
  av1 = (1023 / av1)  - 1;
  av1 = THERMSERIESRESISTOR / av1;
  av2 = (1023 / av2)  - 1;
  av2 = THERMSERIESRESISTOR / av2;

  av8 = (1023 / av8)  - 1;
  av8 = PHOTOSERIESRESISTOR / av8;
  av9 = (1023 / av9)  - 1;
  av9 = PHOTOSERIESRESISTOR / av9;
  av10 = (1023 / av10)  - 1;
  av10 = PHOTOSERIESRESISTOR / av10;
  
  Serial.print(av0);
  Serial.print(", ");
  Serial.print(av1);
  Serial.print(", ");
  Serial.print(av2);
  Serial.print(", ");

  Serial.print(av8);
  Serial.print(", ");
  Serial.print(av9);
  Serial.print(", ");
  Serial.println(av10);

  
  
  // convert the value to resistance
  // av0 = (1023 / average)  - 1;     // (1023/ADC - 1) 
  // av0 = SERIESRESISTOR / average;  // 4.6k / (1023/ADC - 1)
  // Serial.print("Thermistor Analog Resistance "); 
  // Serial.println(av0 + "," + av1 + "," + av2 + "," + av3 + "," + av4 + "," + av5 + "," + av6 + "," + av7 + "," + av8 + "," + av9 + "," + av10 + "," + av11 + "," + av12 + "," + av13 + "," + av14 + "," + av15);

//  float steinhart;
//  steinhart = average / THERMISTORNOMINAL;
//  steinhart = log(steinhart);
//  steinhart /= BCOEFFICIENT;
//  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15);
//  steinhart = 1.0 / steinhart;
//  steinhart -= 273.15;

//  Serial.print("Temperature ");
//  Serial.print(steinhart);
//  Serial.println(" *C");

  delay(1000);
 
}
