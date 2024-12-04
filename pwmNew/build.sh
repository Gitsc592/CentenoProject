#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "IO_PWM_Slider.cpp"

config-pin P9.22 pwm

g++ ./IO_PWM_Slider.cpp ./PWM.cpp ./util.cpp -o IO_PWM_Slider -lpaho-mqtt3c
