int pushButton = 13;

void zhongduanFun(void);

void setup() {
  Serial.begin(115200);
  pinMode(pushButton, INPUT);
  attachInterrupt(pushButton, zhongduanFun, FALLING);
}

void zhongduanFun() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(2000);
}
