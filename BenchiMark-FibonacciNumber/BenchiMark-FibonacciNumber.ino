//値が100,000を超えるまでのフィボナッチ数列を生成する作業を500,000回繰り返すのに要した時間を計測する。
#define DEBUG 0
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  unsigned long x;
  unsigned long prevx;
  unsigned long temp;
  unsigned long start_time, end_time;
  unsigned long time;
  start_time = millis();
  for (unsigned long a = 0; a < 500000; a++) {
    x = 1;
    prevx = 0;
    while (x < 100000) {
      temp = x;
      x = prevx + x;
      prevx = temp;
#if DEBUG
      Serial.println(x);
#endif
    }
  }
  end_time = millis();
  time = end_time - start_time;
  Serial.print("StartTime:");
  Serial.print(start_time);
  Serial.print(" EndTime:");
  Serial.print(end_time);
  Serial.print(" Time:");
  Serial.println(time);
  delay(1000);  //1秒待機
}