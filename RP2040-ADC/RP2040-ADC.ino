void setup()
{
    Serial.begin(115200);
    pinMode(A0, INPUT);
    analogReadResolution(12);
}

void loop()
{
    // float voltage = (float)analogRead(A0) / 1023.0 *3.3;

    float resistance = 10000.0 * (float)analogRead(A0) / (1024.0 - (float)analogRead(A0));

    // Serial.println(voltage);
    // Serial.println(resistance);

    float T0 = 0.0;
    float R0 = 0.0;
    float Bconstant = 3380.0;

    float temperatureBar = 1 / T0 + 1/Bconstant*log(resistance/R0);
    float temperature = 1 / temperatureBar;

    Serial.println(temperature);


    delay(100);
}