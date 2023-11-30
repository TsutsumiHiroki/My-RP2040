

// void loop()
// {
//     float voltage = (float)analogRead(A3) / 1023.0 *3.3;

//     float resistance = 10000.0 * (float)analogRead(A3) / (1023.0 - (float)analogRead(A3));

//     // Serial.println(voltage);
//     Serial.println(resistance);

//     float T0 = 0.0;
//     float R0 = 0.0;
//     float Bconstant = 3380.0;

//     float temperatureBar = 1 / T0 + 1/Bconstant*log(resistance/R0);
//     float temperature = 1 / temperatureBar;

//     Serial.println(temperature);
//     // Serial.println(voltage);

//     delay(100);
// }

// #define THERMISTOR_B 3380
#define THERMISTOR_B 4880
#define THERMISTOR_R0 10000
#define THERMISTOR_T0 25

#define RESISTOR_PULL_DOWN 10000

#ifdef ESP32
#define ANALOG_MAX 4095
#else
#define ANALOG_MAX 1023
#endif

float calcTempratureByResistor(float R, int B, int R0, float T0)
{
    return 1 / (log(R / R0) / B + (1.0 / (T0 + 273))) - 273;
}

float calcResistorByAnalogValue(uint16_t analog, uint16_t analogMax,
                                float resistorPullDown)
{
    return (double)(analogMax - analog) / analog * resistorPullDown;
}

void setup()
{
    Serial.begin(115200);
    pinMode(A3, INPUT);
    // analogReadResolution(10);
}

void loop()
{
    uint16_t valAnalog = analogRead(A3);
    float resistor = calcResistorByAnalogValue(valAnalog, ANALOG_MAX, RESISTOR_PULL_DOWN);
    float temperature = calcTempratureByResistor(resistor, THERMISTOR_B, THERMISTOR_R0, THERMISTOR_T0);
    Serial.print("\e[1;1H");
    Serial.println("Temperature: " + String(temperature) + "C");
    Serial.print("\e[2;1H");
    Serial.println("at " + String(millis())+ "ms");
    delay(100);
}