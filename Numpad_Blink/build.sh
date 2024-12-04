#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "IO_Numpad_Blink.cpp"

g++ ./IO_Numpad_Blink.cpp ./derek_LED.cpp -o IO_Numpad_Blink -lpaho-mqtt3c
