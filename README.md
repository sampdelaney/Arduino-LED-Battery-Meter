Arduino LED Battery Meter
=========================

Simple Arduino program that reads the voltage supplied by a battery and determines its charge based on a specified range. The charge level is then displayed on a LED bar graph.

The aim of this project (or more specifically the code), is to see how well object orientated programming (OOP) works on an embedded platform. Historically, embedded software is developed in a procedural approach which can lead to poor encapsulation and tight coupling, the end result however, can be quite compact and executes much faster.

Currently, this project compiles to around 6KB which is just under 20% of the Arduino Uno's available flash memory.

For a comparison against more procedural implementation of something functionally similar, I found [this](https://github.com/moyoteg/Arduino-Battery-Meter/blob/master/batteryMeter_Arduino) project on GitHub.

Requirements
------------
* [Arduino](http://arduino.cc/en/Main/Products)
* [Arduino IDE] (http://arduino.cc/en/Main/Software#toc1)
* LED Bar Graph
  * 10 x LEDs
  * 10 x 330 Ohm Resistors
* ADC Scaling / Potential Divider
  * 1 x 1K Ohm Resistor (R1)
  * 1 x 1K2 Ohm Resistor (R2)
* 1 x Breadboard/Prototype Board
* 1 x 9V Battery Holder with Battery to measure

### Analog to Digital Converter (ADC)
Most, if not all Arduino's have a built-in 10-bit 0-5V ADC that will measure the voltage on a specified input pin and provide you with a 32-bit integer. Be aware that the value will always be in the range of 0 - 1023 (hence 10-bit = 2^10 - 1). If we were to connect our 9V battery directly to one of the Arduino's ADC pins, we would not be able to tell whether the battery was empty or not until its voltage dropped below 5V (the Aduino's measureable range), and what's worse is that we could damage it. To bring the battery's voltage within range of the Arduino's ADC, we can use a [potential divider](http://en.wikipedia.org/wiki/Voltage_divider) circuit to linearly pre-scale it. Getting the right R1 and R2 values can be quite easy using the formular but getting values for commonly available resistors can be tricky. The actual R1 and R2 values I've specified in the requirements will give a maximum output voltage of 4.9V when the input is 9V, which is fine since you can simply take this into consideration in software. An alternative solution would be to use a variable resistor (potentiometer) and simply "tune" it the desired resistance using a multimeter.

Another feature of the Arduino's ADC is its stability. In other words, there is a degree of variance in the ADC's reading independent of the input voltage, that is, two or measurements can be slightly different even though the input voltage to the ADC never changed. This is usually due to noise in the circuit/Arduino (e.g. transistor switching, DC coupling, etc.). We can use a [low-pass filter](http://en.wikipedia.org/wiki/Low-pass_filter) to remove high frequency transients (jitters) but this would only address some of the noise. An alternative solution would to average the read value in software. The disadvantage of this is that our sample rate would be significantly reduced, but in this particular application it does not matter.

Project To-Do List
------------------
* Move ADC magic numbers in project file to constants to improve readablity
* Allow charge estimation based on non-linear discharging of battery (e.g. lithium-ion)
* Make clear in comments about sequential pin addresses for LED bar graph.
* Consider abstracting out interface to pins for LED bar graph to a shift register instead (SIPO)
