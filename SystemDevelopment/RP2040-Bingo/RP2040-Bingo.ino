#include <TaskManager.h>

// uint8_t pool[75 + 1] = {0};
uint8_t pool[76] = {0};

void setup()
{
    Serial.begin(115200);
    randomSeed(analogRead(A0));

    pinMode(10, INPUT_PULLUP);

    // Tasks.add([]{

    // }
    // )
}

void loop()
{
    uint8_t count = 0;
    uint8_t displaycount = 0;
    uint8_t selectedNumber = 0;

    if (digitalRead(10) == LOW)
    {
        selectedNumber = random(1, 76);

        if (pool[selectedNumber] == 0)
        {
            Serial.print("出た値: ");
            Serial.println(selectedNumber);

            pool[selectedNumber]++;
            count++;

            for (displaycount = 1; displaycount < 76; displaycount++)
            {
                if (pool[displaycount] == 0)
                {
                    Serial.print(" _ ");
                    // digitalWrite(25, LOW);
                }
                else
                {
                    Serial.print(" ");
                    Serial.print(displaycount);
                    Serial.print(" ");
                    // digitalWrite(25, HIGH);
                }
                if (displaycount % 10 == 9)
                {
                    Serial.println("\r");
                }
            }
            Serial.println(" ");
            Serial.println(" ");
        }
        // delay(500);
    }
}



