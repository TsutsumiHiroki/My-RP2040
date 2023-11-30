#pragma once

#include <Arduino.h>
#include "OutputPin.hpp"

class LED
{
public:
    LED(uint8_t pinNumber);


    void on();


    void off();


    void toggle();

private:
    OutputPin* _pin;
};

