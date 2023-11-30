#include "LED.hpp"


LED::LED(uint8_t pinNumber)
{
    _pin = new OutputPin(pinNumber);
}

void LED::on(){
    _pin->high();
}

void LED::off(){
    _pin->low();
}

void LED::toggle(){
    _pin->toggle();
}

