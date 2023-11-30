#include <Arduino.h>

class OutputPin
{
    public:
    OutputPin(uint8_t pinMode);

    
    void high();


    void low();


    void set(bool isHigh);


    bool get();


    void toggle();

    private:
    uint8_t _pinNumber;
};