#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "IO_USR_LED_Blink_Textbox.cpp"

g++ ./IO_USR_LED_Blink_Textbox.cpp ./derek_LED.cpp -o IO_USR_LED_Blink_Textbox -lpaho-mqtt3c
