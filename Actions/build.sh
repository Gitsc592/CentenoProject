#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/29/2024
###
# Builds "IO_Action.cpp"

g++ ./IO_Action.cpp ./derek_LED.cpp -o IO_Action -lpaho-mqtt3c
