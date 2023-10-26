void setup()
{
    pinMode(25, OUTPUT_2MA);
    pinMode(15, INPUT_PULLUP);
}
void loop()
{
    if (digitalRead(15) == LOW){
    digitalWrite(25, HIGH);
    }else
    digitalWrite(25, LOW);
}