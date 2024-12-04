#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "Phys_Pot.cpp"

g++ ./Phys_Pot.cpp ./AnalogIn.cpp -o ./Phys_Pot -lpaho-mqtt3c

