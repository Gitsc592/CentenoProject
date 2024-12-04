#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "Phys_PushButton.cpp"

config-pin P8.16 gpio_pu

g++ ./Phys_PushButton.cpp ./GPIO.cpp -o ./Phys_PushButton -lpaho-mqtt3c -pthread
