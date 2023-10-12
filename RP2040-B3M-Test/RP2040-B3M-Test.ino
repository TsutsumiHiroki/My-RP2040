#include "IcsHardSerialClass.h"


const uint8_t enablePin = 11;
const uint32_t baundRate = 115200;
const uint16_t timeOut = 100;

IcsHardSerialClass B3M(&Serial1, enablePin, baundRate, timeOut);

void setup()
{
    B3M.begin();
    Serial1.begin(115200, SERIAL_8N1);
    Serial.begin(115200);
    pinMode(25, OUTPUT);


    B3M_WriteCmd(0x00, 0x02, 0x28); // 動作モード：Free
    delay(500);

    B3M_WriteCmd(0x00, 0x02, 0x28); // 位置制御モードに設定
    delay(500);

    B3M_WriteCmd(0x00, 0x01, 0x29); // 起動生成タイプ：Even
    delay(500);

    B3M_WriteCmd(0x00, 0x00, 0x5C); // ゲインプリセット：No.0
    delay(500);

    B3M_WriteCmd(0x00, 0x00, 0x28); // 動作モード：Nomal
    delay(500);
}

void loop()
{
    // Positionコマンドで動作角指定
    // B3M_setPos(int id, int Pos, int Time)
    B3M_setPos(0x00, 5000, 500);
    // delay(3000);

    B3M_setPos(0x00, -5000, 1000);
    // delay(3000);

    Serial1.println("Hello Serial1");
    Serial.println("Hello Serial");
    digitalWrite(25, !digitalRead(25));
}

int B3M_WriteCmd(byte id, byte TxData, byte Address)
{

    byte txCmd[8];
    byte rxCmd[5];
    unsigned int reData;
    bool flg;

    txCmd[0] = (byte)(0x08);    // SIZE
    txCmd[1] = (byte)(0x04);    // CMD
    txCmd[2] = (byte)(0x00);    // OP
    txCmd[3] = (byte)(id);      // ID
    txCmd[4] = (byte)(TxData);  // DATA
    txCmd[5] = (byte)(Address); // ADR
    txCmd[6] = (byte)(0x01);    // CNT
    txCmd[7] = (byte)(0x00);    // 初期化

    for (int i = 0; i < 7; i++)
    {
        txCmd[7] += txCmd[i];
        Serial.println(txCmd[i]);
    }
    txCmd[7] = (byte)(txCmd[7]); // SUM

    // 送受信
    flg = B3M.synchronize(txCmd, sizeof txCmd, rxCmd, sizeof rxCmd);
    if (flg == false)
    {
        return -1;
    }
    reData = rxCmd[2];

    return reData;
}

int B3M_setPos(byte id, int Pos, int Time)
{

    byte txCmd[9];
    byte rxCmd[7];
    unsigned int reData;
    bool flg;

    txCmd[0] = (byte)(0x09); // SIZE
    txCmd[1] = (byte)(0x06); // CMD
    txCmd[2] = (byte)(0x00); // OP
    txCmd[3] = (byte)(id);   // ID

    txCmd[4] = (byte)(Pos & 0xFF);      // POS_L
    txCmd[5] = (byte)(Pos >> 8 & 0xFF); // POS_H

    txCmd[6] = (byte)(Time & 0xFF);      // TIME_L
    txCmd[7] = (byte)(Time >> 8 & 0xFF); // TIME_H

    txCmd[8] = 0x00;

    for (int i = 0; i < 8; i++)
    {
        txCmd[8] += txCmd[i];
    }
    txCmd[8] = (byte)(txCmd[8]); // SUM

    // 送受信
    flg = B3M.synchronize(txCmd, sizeof txCmd, rxCmd, sizeof rxCmd);
    if (flg == false)
    {
        return -1;
    }
    reData = rxCmd[2];

    return reData;
}