uint32_t lastTime;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    uint32_t currentTime = millis();

    delay(2);
    
    uint32_t endTime = millis();

    uint32_t louchin = endTime - currentTime;
    showtaskRate();

    delay(10 - louchin); 
}

void showtaskRate(){
    uint32_t currentTime = millis();
    // Serial.println(lastTime);

    uint32_t span = currentTime - lastTime;
    float taskRate = 1.0 / ((float)span / 1000.0);

    Serial.println(taskRate);

    lastTime = currentTime;
}