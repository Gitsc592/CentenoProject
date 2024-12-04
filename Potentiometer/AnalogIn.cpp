//////////////////////////////////////////
// Filename : AnalogIn.cpp
// Author : Sed Centeno
// Date : 11/12/2024
//
// Description :
// Implements the class functions defined in "AnalogIn.h"
//////////////////////////////////////////

#include <fstream>
#include <sstream>
#include "AnalogIn.h"

#define ANALOG_PATH "/sys/bus/iio/devices/iio:device0/"

using namespace std;

AnalogIn::AnalogIn(){
}

AnalogIn::~AnalogIn(){
}

AnalogIn::AnalogIn(unsigned int n){
  number = n;
}

void AnalogIn::setNumber(unsigned int n){
  number = n;
  return;
}

int AnalogIn::readAdcSample(){
  int adc;

  stringstream ss;
  fstream fs;

  ss << ANALOG_PATH << "in_voltage" << number << "_raw";
  
  fs.open(ss.str().c_str(), fstream::in);
  fs >> adc;
  fs.close();

  return adc;
}
