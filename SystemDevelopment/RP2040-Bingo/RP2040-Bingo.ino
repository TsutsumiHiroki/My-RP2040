const uint8_t buttonPin = 10;
const uint8_t maxNumber = 75;
const uint8_t arraySize = 25;

uint8_t numbers[arraySize];
int ind = 0;

void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("BINGO");
    Serial.println("Press button...");
    randomSeed(analogRead(A0));
}

void loop()
{
    if (digitalRead(buttonPin) == LOW)
    {
        delay(300);
        if (ind < arraySize)
        {
            uint8_t bingoNumber = random(1, maxNumber + 1);
            if (!contains(numbers, bingoNumber))
            {
                numbers[ind] = bingoNumber;
                ind++;

                showNumberframe();

                Serial.print("\e[2;5H");
                Serial.println(bingoNumber);
                Serial.println("");
                showNumbers();
            }
        }
        else
        {
            Serial.println("No more numbers");
        }
    }
}

bool contains(uint8_t array[], uint8_t value)
{
    for (uint8_t countArraysize = 0; countArraysize < arraySize; countArraysize++)
    {
        if (array[countArraysize] == value)
        {
            return true;
        }
    }
    return false;
}

void showNumbers()
{
    Serial.println("Numbers so far: ");
    for (uint8_t countShownumber = 0; countShownumber < ind; countShownumber++)
    {
        Serial.print(numbers[countShownumber]);
        Serial.print(" | ");
    }
    Serial.println("");
    Serial.println("");
}

void showNumberframe()
{
    Serial.print("\e[1;1H");
    Serial.print("-");
    Serial.print("\e[1;2H");
    Serial.print("-");
    Serial.print("\e[1;3H");
    Serial.print("Number");
    Serial.print("\e[1;9H");
    Serial.print("-");
    Serial.print("\e[1;10H");
    Serial.print("-");
    Serial.print("\e[2;1H");
    Serial.print("|");
    Serial.print("\e[2;10H");
    Serial.print("|");
    Serial.print("\e[3;1H");
    Serial.print("-");
    Serial.print("\e[3;2H");
    Serial.print("-");
    Serial.print("\e[3;3H");
    Serial.print("-");
    Serial.print("\e[3;4H");
    Serial.print("-");
    Serial.print("\e[3;5H");
    Serial.print("-");
    Serial.print("\e[3;6H");
    Serial.print("-");
    Serial.print("\e[3;7H");
    Serial.print("-");
    Serial.print("\e[3;8H");
    Serial.print("-");
    Serial.print("\e[3;9H");
    Serial.print("-");
    Serial.print("\e[3;10H");
    Serial.print("-");
}