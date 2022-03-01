//uint8_t 相当于typedef unsigned char uint8_t
#define LEN 100
uint8_t buf[LEN];
uint8_t i = 0;
void setup() {
  Serial.begin(115200); //串口初始化, 波特率115200
}

void loop() {
  //available() 返回接受到的字节数
  if(Serial.available()) {
    delay(100);
    Serial.read(buf, Serial.available());
    Serial.printf("your input: %s\r\n", buf);
    memset(buf, 0, LEN);
  }
}

#if 0
void loop() {
  while(Serial.available()) {
    buf[i++] = Serial.read();
  }
  if (i > 0) {
    Serial.printf("you input: %s\r\n", buf);
    memset(buf, 0, LEN);
    i = 0;
  }
}
#endif

#if 0
void loop() {
  //available() 返回接受到的字节数
  if(Serial.available()) {
    Serial.read(buf, Serial.available());
    Serial.printf("your input: %s\r\n", buf);
    memset(buf, 0, LEN);
  }
}
#endif
