uint8_t IN1 = 3;
uint8_t IN2 = 2;

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(25, OUTPUT);
}

void loop()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(25, HIGH);

    delay(700);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    delay(500);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(25, LOW);

    delay(700);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    delay(500);
}