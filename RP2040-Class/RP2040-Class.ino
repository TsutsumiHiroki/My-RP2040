#include "LED.hpp"
#include <TaskManager.h>

LED led(25);

void setup()
{
    Serial.begin(115200);
    Tasks.add("Toggle", []()
              { led.toggle(); });
}

void loop()
{
    Tasks.update();
    // Tasks["Toggle"]->startIntervalMsecForCount(50, 6);
    Tasks["Toggle"]->startFps(100);
    // led.toggle();
    // delay(100);
}