#include "Adc.h"
#include "BatteryMeter.h"
#include "LedBargraph.h"
#include <Arduino.h>

// Battery Attributes
const float BATTERY_FULL = 11.5;
const float BATTERY_EMPTY = 9.5;

// ADC on pin 0, 10-bit, 0V-5V
Adc adc(1, 10, 0, 5);
// Battery meter bound to the ADC
BatteryMeter batteryMeter(BATTERY_EMPTY, BATTERY_FULL, &adc);
// 10 segment LED bargraph starting on pin 0
LedBargraph ledBargraph(10, 0, BATTERY_EMPTY, BATTERY_FULL);

float batteryPercentage;

void setup() {
  //
  Serial.begin(9600);
}

void loop() {
  // measure battery
  batteryPercentage = batteryMeter.getPercentage();
  // display it on the bargraph
  ledBargraph.setValue(batteryPercentage);
  // print the value to serial
  Serial.println(batteryPercentage);
}
