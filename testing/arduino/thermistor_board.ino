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
#define T3 A3
#define T4 A4
#define T5 A5
#define T6 A6
#define T7 A7
#define T8 A8
#define T9 A9
#define T10 A10
#define T11 A11
#define T12 A12
#define T13 A13
#define T14 A14
#define T15 A15
#define THERMISTORNOMINAL 100000
#define TEMPERATURENOMINAL 25
#define NUMSAMPLES 5
#define BCOEFFICIENT 3950
#define SERIESRESISTOR 100000

int samples0[NUMSAMPLES];
int samples1[NUMSAMPLES];
int samples2[NUMSAMPLES];
int samples3[NUMSAMPLES];
int samples4[NUMSAMPLES];
int samples5[NUMSAMPLES];
int samples6[NUMSAMPLES];
int samples7[NUMSAMPLES];
int samples8[NUMSAMPLES];
int samples9[NUMSAMPLES];
int samples10[NUMSAMPLES];
int samples11[NUMSAMPLES];
int samples12[NUMSAMPLES];
int samples13[NUMSAMPLES];
int samples14[NUMSAMPLES];
int samples15[NUMSAMPLES];


void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  uint8_t i;
  float av0;
  float av1;
  float av2;
  float av3;
  float av4;
  float av5;
  float av6;
  float av7;
  float av8;
  float av9;
  float av10;
  float av11;
  float av12;
  float av13;
  float av14;
  float av15;

  //take N samples w/ slight delay
  for (i = 0; i < NUMSAMPLES; i++) {
    samples0[i] = analogRead(T0);
    samples1[i] = analogRead(T1);
    samples2[i] = analogRead(T2);
    samples3[i] = analogRead(T3);
    samples4[i] = analogRead(T4);
    samples5[i] = analogRead(T5);
    samples6[i] = analogRead(T6);
    samples7[i] = analogRead(T7);
    samples8[i] = analogRead(T8);
    samples9[i] = analogRead(T9);
    samples10[i] = analogRead(T10);
    samples11[i] = analogRead(T11);
    samples12[i] = analogRead(T12);
    samples13[i] = analogRead(T13);
    samples14[i] = analogRead(T14);
    samples15[i] = analogRead(T15);
  }

  //average samples
  av0 = 0;
  av1 = 0;
  av2 = 0;
  av3 = 0;
  av4 = 0;
  av5 = 0;
  av6 = 0;
  av7 = 0;
  av8 = 0;
  av9 = 0;
  av10 = 0;
  av11 = 0;
  av12 = 0;
  av13 = 0;
  av14 = 0;
  av15 = 0;
  for(i = 0; i < NUMSAMPLES; i++) {
    av0 += samples0[i] / NUMSAMPLES;
    av1 += samples1[i] / NUMSAMPLES;
    av2 += samples2[i] / NUMSAMPLES;
    av3 += samples3[i] / NUMSAMPLES;
    av4 += samples4[i] / NUMSAMPLES;
    av5 += samples5[i] / NUMSAMPLES;
    av6 += samples6[i] / NUMSAMPLES;
    av7 += samples7[i] / NUMSAMPLES;
    av8 += samples8[i] / NUMSAMPLES;
    av9 += samples9[i] / NUMSAMPLES;
    av10 += samples10[i] / NUMSAMPLES;
    av11 += samples11[i] / NUMSAMPLES;
    av12 += samples12[i] / NUMSAMPLES;
    av13 += samples13[i] / NUMSAMPLES;
    av14 += samples14[i] / NUMSAMPLES;
    av15 += samples15[i] / NUMSAMPLES;
  }

  av0 = (1023 / av0)  - 1;
  av0 = SERIESRESISTOR / av0;
  av1 = (1023 / av1)  - 1;
  av1 = SERIESRESISTOR / av1;
  av2 = (1023 / av2)  - 1;
  av2 = SERIESRESISTOR / av2;
  av3 = (1023 / av3)  - 1;
  av3 = SERIESRESISTOR / av3;
  av4 = (1023 / av4)  - 1;
  av4 = SERIESRESISTOR / av4;
  av5 = (1023 / av5)  - 1;
  av5 = SERIESRESISTOR / av5;
  av6 = (1023 / av6)  - 1;
  av6 = SERIESRESISTOR / av6;
  av7 = (1023 / av7)  - 1;
  av7 = SERIESRESISTOR / av7;
  av8 = (1023 / av8)  - 1;
  av8 = SERIESRESISTOR / av8;
  av9 = (1023 / av9)  - 1;
  av9 = SERIESRESISTOR / av9;
  av10 = (1023 / av10)  - 1;
  av10 = SERIESRESISTOR / av10;
  av11 = (1023 / av11)  - 1;
  av11 = SERIESRESISTOR / av11;
  av12 = (1023 / av12)  - 1;
  av12 = SERIESRESISTOR / av12;
  av13 = (1023 / av13)  - 1;
  av13 = SERIESRESISTOR / av13;
  av14 = (1023 / av14)  - 1;
  av14 = SERIESRESISTOR / av14;
  av15 = (1023 / av15)  - 1;
  av15 = SERIESRESISTOR / av15;
  
  Serial.print(av0);
  Serial.print(", ");
  Serial.print(av1);
  Serial.print(", ");
  Serial.print(av2);
  Serial.print(", ");
  Serial.print(av3);
  Serial.print(", ");
  Serial.print(av4);
  Serial.print(", ");
  Serial.print(av5);
  Serial.print(", ");
  Serial.print(av6);
  Serial.print(", ");
  Serial.print(av7);
  Serial.print(", ");
  Serial.print(av8);
  Serial.print(", ");
  Serial.print(av9);
  Serial.print(", ");
  Serial.print(av10);
  Serial.print(", ");
  Serial.print(av11);
  Serial.print(", ");
  Serial.print(av12);
  Serial.print(", ");
  Serial.print(av13);
  Serial.print(", ");
  Serial.print(av14);
  Serial.print(", ");
  Serial.println(av15);

  
  
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
