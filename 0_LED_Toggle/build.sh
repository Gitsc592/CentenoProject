#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "IO_Toggle_LED.cpp"

config-pin P9.12 gpio

g++ ./IO_Toggle_LED.cpp ./GPIO.cpp -o IO_Toggle_LED -lpaho-mqtt3c -pthread
