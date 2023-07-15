void setup()
{
    pinMode(25, OUTPUT_2MA);
}
void loop()
{
    digitalWrite(25, 0x01);
    delay(10);
    digitalWrite(25, 0x00);
    delay(100);

}