void setup()
{
    Serial.begin(115200);
}

void setup1()
{
    Serial.begin(115200);
}

void loop()
{
    rp2040.fifo.push(2040);
    delay(111);
}

void loop1()
{
    // uint32_t ooo;
    Serial.print("Core2: ");
    Serial.println(rp2040.fifo.available());
    Serial.println(rp2040.fifo.pop());
    Serial.println(rp2040.fifo.pop_nb());
    // Serial.println();
    delay(233);
}