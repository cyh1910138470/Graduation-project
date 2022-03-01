#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>

const char *ssid = "kenshin";
const char *password = "123456789";

void setup() {
  Serial.begin(115200);
  Serial.println("Serial init finish");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("WiFi connect finish!");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(2000);
  char flag = 0;
  if (flag == 0) {
    Serial.println("进入了flag=0 开始发送请求");
    HTTPClient http;
    http.begin("http://192.168.100.187:3000/");
    int httpCode = http.GET();
    if ((httpCode = 200 || httpCode > 200) && httpCode < 300) {
      Serial.println("状态码正确");
      String payload = http.getString();
      Serial.println(payload);
      http.end();
    }
  }

}
