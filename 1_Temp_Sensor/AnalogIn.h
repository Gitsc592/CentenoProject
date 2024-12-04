/////////////////////////////////////////////////
// Filename : AnalogIn.h
// Author : Sed Centeno
// Date : 11/12/2024
//
// Description :
// Header file that defines that "AnalogIn" class
/////////////////////////////////////////////////

class AnalogIn{
  private:
    unsigned int number;
  public:
    // Default Constructor
    AnalogIn();
    // Constructor
    AnalogIn(unsigned int n);
    virtual unsigned int getNumber() {return number; } // inline function implementation.
    virtual void setNumber(unsigned int n);
    virtual int readAdcSample();
    // Deconstructor
    virtual ~AnalogIn();
};
