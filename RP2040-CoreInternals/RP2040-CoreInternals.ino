#include<TaskManager.h>

void setup()
{
    Serial.begin(115200);
    pinMode(25, OUTPUT);


    Tasks.add("TEST", [] {
    Serial.print("f_cpu: ");
    Serial.println(rp2040.f_cpu());
    Serial.print("cpuid: ");
    Serial.println(rp2040.cpuid());

    analogReadResolution(12);
    int readAnalog_Voltage = analogRead(A1);
    float voltage = readAnalog_Voltage * 3.3 / 4095.0;
    Serial.print("analogRead: ");
    Serial.println(readAnalog_Voltage);
    Serial.print("Voltage: ");
    Serial.println(voltage);

    })->startFps(10);
}

void loop()
{
    Tasks.update();
}
