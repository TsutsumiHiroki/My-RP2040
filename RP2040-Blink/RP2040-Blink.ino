void setup()
{
    pinMode(25, OUTPUT_2MA);
    // pinMode(15, INPUT_PULLUP);
}
void loop()
{
    // if (digitalRead(15) == LOW){
    digitalWrite(25, HIGH);
    // }else
    delay(100);
    digitalWrite(25, LOW);
    delay(100);
}