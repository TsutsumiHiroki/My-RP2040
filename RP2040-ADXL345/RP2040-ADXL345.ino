/***************************************************************************************
 *  @file:    adx345_sample1.ino 
 *  @date:    6-July-2020
 *  @brief:   加速度センサー(ADXL345）のデータ取得サンプルプログラム
 *  @Arduino_IDEVersion:  Arduiono 1.8.12  
 *  @test boards: Arduino Nano & ADXL345 evaluation board
 * 
 *  Copyright (C) <2020> Macnica Inc. All Rights Reserved.\n
 *  This software is licensed "AS IS". 
 *  Please perform use of this software by a user's own responsibility and expense.
 *  It cannot guarantee in the maker side about the damage which occurred by the ab-
 *  ility not to use or use this software, and all damage that occurred secondarily.
/***************************************************************************************/
/*インクルードファイル*/
#include <Wire.h>                         //I2Cライブラリインポート
/*使用するマクロの定義*/
#define ADXL345_I2C_ADRESS        0x1D    //ADXL345 I2C address
#define ADXL345_DEV_ID            0xE5    //ADXL345 Device ID Number
#define ADXL345_SCALE_FACTOR      0.0039  //ADXL345 Scale Factor at ±2g range 
#define ADXL345_DEVID         0x00        //ADXL345 Device ID Address
#define ADXL345_DATAX0        0x32        //ADXL345 X-Axis Data0 Address
#define ADXL345_POWER_CTL     0x2D        //ADXL345Power Management Adress
/*関数プロトタイプ宣言*/
void adxl345_set_data(uint8_t ucReg, uint8_t ucData);                   
void adxl345_get_data(uint8_t ucReg, uint8_t *ucData, uint8_t ucSize); 
void adxl345_get_axi(float *pfData);

/*メイン関数*/
void setup() {
  // Arduino シリアルモニターの初期化
  Serial.begin(115200);    
  //Arduino I2Cペリフェラル初期化
  
  Wire.begin();        
  Wire.setClock(400000);
  //ArduinoとADXL345のＩ２Ｃ通信確認
  uint8_t ucData;                  
  adxl345_get_data(ADXL345_DEVID, &ucData, 1); //デバイスＩＤ取得
  if(ucData !=  ADXL345_DEV_ID){
    Serial.println(F("I2C connection fail.Try again."));
  }         
  //ADXL345を測定モードへ変更  
  adxl345_set_data(ADXL345_POWER_CTL, 0x08);   
  // adxl345_set_data(0x31, 0b00000011);
  delay(100);
}
void loop() {
  float axiData[3];
  //加速度データ取得
  adxl345_get_axi(axiData);
  //加速度データの表示
  Serial.print(" X[g]:");Serial.print(axiData[0]);Serial.print(",");
  Serial.print(" Y[g]:");Serial.print(axiData[1]);Serial.print(",");
  Serial.print(" Z[g]:");Serial.print(axiData[2]);
  Serial.println();
  //10msecの遅延時間
  delay(10);
}

/*ADXL345のレジスタデータ書き込み関数*/
void adxl345_set_data(uint8_t ucReg, uint8_t ucData){
  Wire.beginTransmission(ADXL345_I2C_ADRESS); 
  Wire.write(ucReg);
  Wire.write(ucData);  
  Wire.endTransmission(true); 
}
/*ADXL345のレジスタデータ読み込み関数*/
void adxl345_get_data(uint8_t ucReg, uint8_t *ucData, uint8_t ucSize){
  uint8_t cnt = 0;
  Wire.beginTransmission(ADXL345_I2C_ADRESS); 
  Wire.write(ucReg);    
  Wire.endTransmission(false); 
  Wire.requestFrom(ADXL345_I2C_ADRESS, ucSize, true);
  while(Wire.available()){
    ucData[cnt] = Wire.read();
    cnt++;   
  }
}
/*ADXL345 X,Y,Zデータ取得関数*/
void adxl345_get_axi(float *pfData){
  uint8_t ucBuf[6];
  int16_t acc[3];
  adxl345_get_data(ADXL345_DATAX0, ucBuf, 6);
  acc[0] =((int16_t)ucBuf[1] << 8) | ucBuf[0];  
  acc[1] =((int16_t)ucBuf[3] << 8) | ucBuf[2];
  acc[2] =((int16_t)ucBuf[5] << 8) | ucBuf[4];
  pfData[0] = acc[0] * ADXL345_SCALE_FACTOR;
  pfData[1] = acc[1] * ADXL345_SCALE_FACTOR;
  pfData[2] = acc[2] * ADXL345_SCALE_FACTOR;
}