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
int b = 0;
void loop() {
  char str1[100];
  char str2[100];
  sprintf(str1, "page0.n0.val=%d", a);
  TJC.print(str1);
  SendEnd();
  sprintf(str2, "page1.n0.val=%d", b);
  TJC.print(str2);
  SendEnd();
  a++;
  b++;
  b++;
  Serial.println("代码执行断点1");
  Serial.println(a);
  Serial.println(b);
  delay(2000);
}
