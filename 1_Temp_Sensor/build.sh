#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "Phys_Temp_Sensor.cpp" & "IO_Temp_Sensor.cpp"


### 1_Temp_Sensor
g++ ./Phys_Temp_Sensor.cpp ./AnalogIn.cpp -o ./Phys_Temp_Sensor -lpaho-mqtt3c
g++ ./IO_Temp_Sensor.cpp ./derek_LED.cpp -o ./IO_Temp_Sensor -lpaho-mqtt3c

