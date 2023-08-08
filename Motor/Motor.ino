// uint8_t IN1 = 3;
// uint8_t IN2 = 2;

int IN1 = 3;
int IN2 = 2;


void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
}

void loop()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    delay(2000);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    delay(3000);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    delay(1000);
}