// #include <Arduino.h>


// void setup()
// {
//     // pinMode(LED_BUILTIN, OUTPUT);
//     pinMode(0, INPUT);
//     Serial.begin(115200);
//     Serial.println("setup");
// }

// void loop()
// {
//     bool toggle = digitalRead(0);
//     Serial.print("toggle: ");
//     Serial.println(toggle);
//     // digitalWrite(LED_BUILTIN, HIGH);
//     delay(100);
//     // digitalWrite(LED_BUILTIN, LOW);
//     // delay(300);
//     // if(digitalRead(0) == )
// }

void setup()
{
    Serial.begin(115200);
    analogReadResolution(12);
    // pinMode(A0, INPUT);
}

void loop()
{
    int16_t readAnalog = analogRead(A0);
    float readVoltage = (float)readAnalog * 3.3 / 4095.0;

    Serial.print("Voltage: ");
    Serial.println(readVoltage);
    delay(100);
}