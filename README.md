Arduino LED Battery Meter
=========================

Simple Arduino program that reads the voltage supplied by a battery and determines its charge based on a specified range. The charge level is then displayed on a LED bar graph.

The aim of this project (or more specifically the code), is to see how well object orientated programming (OOP) works on an embedded platform. Historically, embedded software is developed in a procedural approach which can lead to poor encapsulation and tight coupling, the end result however, can be quite compact and executes much faster.

Currently, this project compiles to around 6KB which is just under 20% of the Arduino Uno's available flash memory.

For a comparison against more procedural implementation of something functionally similar, I found [this](https://github.com/moyoteg/Arduino-Battery-Meter/blob/master/batteryMeter_Arduino) project on GitHub.
