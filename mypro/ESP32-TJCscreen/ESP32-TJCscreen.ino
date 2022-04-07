#define TJC Serial2

void SendEnd() {
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);
}

void setup() {
  Serial.begin(115200);
  Serial.println("等待串口屏连接");
  TJC.begin(115200);
  while (TJC.read() >= 0);
  Serial.println("串口屏已连接");
  Serial.println(TJC.read());
}
int a = 0;
void loop() {
  char str[100];
  sprintf(str, "n0.val=%d", a);
  TJC.print(str);
  SendEnd();
  a++;
//  Serial.println("123");
  delay(500);
  Serial.println("代码执行断点");
  Serial.println(a);
}
