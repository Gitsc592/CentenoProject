///////////////////////////////////////////////////
// Filename : derek_LED.h
// Author : Sed Centeno
// Date : 10/28/2024
//
// Description :
// Header file for the LED Class, used in myApp.cpp
///////////////////////////////////////////////////

using namespace std;

class LED{
  private:
    string path;
    int number; // LED # (usr0, usr1)
    virtual void writeLED(string filename, string value);
    virtual void removeTrigger();

  public:
    LED(int number); // LED # (usr0, usr1)
    virtual void turnOn();
    virtual void turnOff();
    virtual void flash(string delayms);
    virtual void outputState();
    virtual ~LED();
};
