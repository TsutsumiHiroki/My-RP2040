// #include <TaskManager.h>

void setup()
{
    Serial.begin(115200);
}

void setup1()
{
    Serial.begin(115200);
    pinMode(25, OUTPUT);
}

void loop()
{
    Serial.println("Hello RP2040 Core1");
    Serial.print("Core1: ");
    
    delay(100);
    Serial.println(millis());
}

void loop1()
{
    Serial.println("Hello RP2040 Core2");
    Serial.print("Core2: ");
    

    digitalWrite(25 ,0x01);
    delay(300);
    digitalWrite(25, 0x00);
    delay(200);
    Serial.println(millis());
}