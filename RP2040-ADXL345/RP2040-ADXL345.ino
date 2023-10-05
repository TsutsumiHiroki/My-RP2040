#include <Wire.h>
#include <TaskManager.h>

#define AclSenAdrs 0x1D
int AclSen, AclSenL, AclSenH;

void setup()
{
    Wire.begin();
    Serial.begin(115200);
    Serial.println("setup");

    Wire.beginTransmission(AclSenAdrs);
    Wire.write(0x2D);
    Wire.write(0x08);

    Wire.write(0x31);
    Wire.write(0b0000011);
    Wire.endTransmission();

    Tasks.add("getID", []
              {

        Wire.beginTransmission(AclSenAdrs);
        Wire.write(0x36);
        Wire.endTransmission();
        Wire.requestFrom(AclSenAdrs, 2);
        while (Wire.available())
        {
            AclSenL = Wire.read();
            AclSenH = Wire.read();
        }

        AclSen = 0;
        AclSen = AclSenL + AclSenH;
        Serial.print("AclSen:");
        Serial.println(AclSen); })
        ->startFps(10);
}

void loop()
{
    Tasks.update();
}