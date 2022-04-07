#define TJC Serial2
#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>

//定义wifi名和wifi密码
const char *ssid = "kenshin";
const char *password = "123456789";

void SendEnd() {
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);
}

void setup() {
  Serial.begin(115200);
  Serial.println("等待wifi连接");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("."); //等待wifi的
  }
  Serial.println("WiFi connect success!");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
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
  Serial.println("开始发送请求");
  HTTPClient http;
  http.begin("http://192.168.204.187:3000/");
  int httpCode = http.GET();
  if ((httpCode = 200 || httpCode > 200) && httpCode < 300) {
    Serial.println("状态码正确");
    String payload = http.getString();
    String json = payload;
    DynamicJsonDocument doc(5000);
    deserializeJson(doc, json);
    int LocalExistingConfirm = doc["LocalExistingConfirm"].as<int>();
    int ExistingConfirmInt = doc["ExistingConfirm"].as<int>();
    int TotalConfirm = doc["TotalConfirm"].as<int>();
    int noSymptom = doc["noSymptom"].as<int>();
    int incrNoSymptom = doc["incrNoSymptom"].as<int>();
    int inputTotal = doc["inputTotal"].as<int>();
    int inputIncrement = doc["inputIncrement"].as<int>();
    int TotalDead = doc["TotalDead"].as<int>();
    int TotalDeadIncrement = doc["TotalDeadIncrement"].as<int>();
    int AbroadExistingConfirm = doc["AbroadExistingConfirm"].as<int>();
    int AbroadConfirm = doc["AbroadConfirm"].as<int>();
    int AbroadHeal = doc["AbroadHeal"].as<int>();
    int AbroadDead = doc["AbroadDead"].as<int>();
    String lastUpdateTime = doc["lastUpdateTime"].as<String>();
    String Provinces = doc["Provinces"].as<String>();

    //json数组的处理
    DynamicJsonDocument doc1(5000);
    deserializeJson(doc1, Provinces);
    
    String xiangGangName = doc1[0]["name"].as<String>();
    int xiangGangTotalConfirm = doc1[0]["TotalConfirm"].as<int>();
    int xiangGangTotalHeal = doc1[0]["TotalHeal"].as<int>();
    int xiangGangTotalDead = doc1[0]["TotalDead"].as<int>();

    String huBeiName = doc1[1]["name"].as<String>();
    int huBeiTotalConfirm = doc1[1]["TotalConfirm"].as<int>();
    int huBeiTotalHeal = doc1[1]["TotalHeal"].as<int>();
    int huBeiTotalDead = doc1[1]["TotalDead"].as<int>();

    String jiLinName = doc1[2]["name"].as<String>();
    int jiLinTotalConfirm = doc1[2]["TotalConfirm"].as<int>();
    int jiLinTotalHeal = doc1[2]["TotalHeal"].as<int>();
    int jiLinTotalDead = doc1[2]["TotalDead"].as<int>();

    String taiWanName = doc1[3]["name"].as<String>();
    int taiWanTotalConfirm = doc1[3]["TotalConfirm"].as<int>();
    int taiWanTotalHeal = doc1[3]["TotalHeal"].as<int>();
    int taiWanTotalDead = doc1[3]["TotalDead"].as<int>();

    String guangDongName = doc1[4]["name"].as<String>();
    int guangDongTotalConfirm = doc1[4]["TotalConfirm"].as<int>();
    int guangDongTotalHeal = doc1[4]["TotalHeal"].as<int>();
    int guangDongTotalDead = doc1[4]["TotalDead"].as<int>();

    String shangHaiName = doc1[5]["name"].as<String>();
    int shangHaiTotalConfirm = doc1[5]["TotalConfirm"].as<int>();
    int shangHaiTotalHeal = doc1[5]["TotalHeal"].as<int>();
    int shangHaiTotalDead = doc1[5]["TotalDead"].as<int>();

    String shanXi1Name = doc1[6]["name"].as<String>();
    int shanXi1TotalConfirm = doc1[6]["TotalConfirm"].as<int>();
    int shanXi1TotalHeal = doc1[6]["TotalHeal"].as<int>();
    int shanXi1TotalDead = doc1[6]["TotalDead"].as<int>();

    String heNanName = doc1[7]["name"].as<String>();
    int heNanTotalConfirm = doc1[7]["TotalConfirm"].as<int>();
    int heNanTotalHeal = doc1[7]["TotalHeal"].as<int>();
    int heNanTotalDead = doc1[7]["TotalDead"].as<int>();

    String fuJianName = doc1[8]["name"].as<String>();
    int fuJianTotalConfirm = doc1[8]["TotalConfirm"].as<int>();
    int fuJianTotalHeal = doc1[8]["TotalHeal"].as<int>();
    int fuJianTotalDead = doc1[8]["TotalDead"].as<int>();

    String zheJiangName = doc1[9]["name"].as<String>();
    int zheJiangTotalConfirm = doc1[9]["TotalConfirm"].as<int>();
    int zheJiangTotalHeal = doc1[9]["TotalHeal"].as<int>();
    int zheJiangTotalDead = doc1[9]["TotalDead"].as<int>();

    String shanDongName = doc1[10]["name"].as<String>();
    int shanDongTotalConfirm = doc1[10]["TotalConfirm"].as<int>();
    int shanDongTotalHeal = doc1[10]["TotalHeal"].as<int>();
    int shanDongTotalDead = doc1[10]["TotalDead"].as<int>();

    String heilongJiangName = doc1[11]["name"].as<String>();
    int heilongJiangTotalConfirm = doc1[11]["TotalConfirm"].as<int>();
    int heilongJiangTotalHeal = doc1[11]["TotalHeal"].as<int>();
    int heilongJiangTotalDead = doc1[11]["TotalDead"].as<int>();

    String yunNanName = doc1[12]["name"].as<String>();
    int yunNanTotalConfirm = doc1[12]["TotalConfirm"].as<int>();
    int yunNanTotalHeal = doc1[12]["TotalHeal"].as<int>();
    int yunNanTotalDead = doc1[12]["TotalDead"].as<int>();

    String jiangSuName = doc1[13]["name"].as<String>();
    int jiangSuTotalConfirm = doc1[13]["TotalConfirm"].as<int>();
    int jiangSuTotalHeal = doc1[13]["TotalHeal"].as<int>();
    int jiangSuTotalDead = doc1[13]["TotalDead"].as<int>();

    String heBeiName = doc1[14]["name"].as<String>();
    int heBeiTotalConfirm = doc1[14]["TotalConfirm"].as<int>();
    int heBeiTotalHeal = doc1[14]["TotalHeal"].as<int>();
    int heBeiTotalDead = doc1[14]["TotalDead"].as<int>();

    String tianJinName = doc1[15]["name"].as<String>();
    int tianJinTotalConfirm = doc1[15]["TotalConfirm"].as<int>();
    int tianJinTotalHeal = doc1[15]["TotalHeal"].as<int>();
    int tianJinTotalDead = doc1[15]["TotalDead"].as<int>();

    String beiJinName = doc1[16]["name"].as<String>();
    int beiJinTotalConfirm = doc1[16]["TotalConfirm"].as<int>();
    int beiJinTotalHeal = doc1[16]["TotalHeal"].as<int>();
    int beiJinTotalDead = doc1[16]["TotalDead"].as<int>();

    String neimengGuName = doc1[17]["name"].as<String>();
    int neimengGuTotalConfirm = doc1[17]["TotalConfirm"].as<int>();
    int neimengGuTotalHeal = doc1[17]["TotalHeal"].as<int>();
    int neimengGuTotalDead = doc1[17]["TotalDead"].as<int>();

    String siChuanName = doc1[18]["name"].as<String>();
    int siChuanTotalConfirm = doc1[18]["TotalConfirm"].as<int>();
    int siChuanTotalHeal = doc1[18]["TotalHeal"].as<int>();
    int siChuanTotalDead = doc1[18]["TotalDead"].as<int>();

    String liaoNinName = doc1[19]["name"].as<String>();
    int liaoNinTotalConfirm = doc1[19]["TotalConfirm"].as<int>();
    int liaoNinTotalHeal = doc1[19]["TotalHeal"].as<int>();
    int liaoNinTotalDead = doc1[19]["TotalDead"].as<int>();

    String guangXiName = doc1[20]["name"].as<String>();
    int guangXiTotalConfirm = doc1[20]["TotalConfirm"].as<int>();
    int guangXiTotalHeal = doc1[20]["TotalHeal"].as<int>();
    int guangXiTotalDead = doc1[20]["TotalDead"].as<int>();

    String huNanName = doc1[21]["name"].as<String>();
    int huNanTotalConfirm = doc1[21]["TotalConfirm"].as<int>();
    int huNanTotalHeal = doc1[21]["TotalHeal"].as<int>();
    int huNanTotalDead = doc1[21]["TotalDead"].as<int>();

    String jiangXiName = doc1[22]["name"].as<String>();
    int jiangXiTotalConfirm = doc1[22]["TotalConfirm"].as<int>();
    int jiangXiTotalHeal = doc1[22]["TotalHeal"].as<int>();
    int jiangXiTotalDead = doc1[22]["TotalDead"].as<int>();

    String anHuiName = doc1[23]["name"].as<String>();
    int anHuiTotalConfirm = doc1[23]["TotalConfirm"].as<int>();
    int anHuiTotalHeal = doc1[23]["TotalHeal"].as<int>();
    int anHuiTotalDead = doc1[23]["TotalDead"].as<int>();

    String xinJiangName = doc1[24]["name"].as<String>();
    int xinJiangTotalConfirm = doc1[24]["TotalConfirm"].as<int>();
    int xinJiangTotalHeal = doc1[24]["TotalHeal"].as<int>();
    int xinJiangTotalDead = doc1[24]["TotalDead"].as<int>();

    String chongQinName = doc1[25]["name"].as<String>();
    int chongQinTotalConfirm = doc1[25]["TotalConfirm"].as<int>();
    int chongQinTotalHeal = doc1[25]["TotalHeal"].as<int>();
    int chongQinTotalDead = doc1[25]["TotalDead"].as<int>();

    String ganSuName = doc1[26]["name"].as<String>();
    int ganSuTotalConfirm = doc1[26]["TotalConfirm"].as<int>();
    int ganSuTotalHeal = doc1[26]["TotalHeal"].as<int>();
    int ganSuTotalDead = doc1[26]["TotalDead"].as<int>();

    String shanXi2Name = doc1[27]["name"].as<String>();
    int shanXi2TotalConfirm = doc1[27]["TotalConfirm"].as<int>();
    int shanXi2TotalHeal = doc1[27]["TotalHeal"].as<int>();
    int shanXi2TotalDead = doc1[27]["TotalDead"].as<int>();

    String haiNanName = doc1[28]["name"].as<String>();
    int haiNanTotalConfirm = doc1[28]["TotalConfirm"].as<int>();
    int haiNanTotalHeal = doc1[28]["TotalHeal"].as<int>();
    int haiNanTotalDead = doc1[28]["TotalDead"].as<int>();

    String guiZhouName = doc1[29]["name"].as<String>();
    int guiZhouTotalConfirm = doc1[29]["TotalConfirm"].as<int>();
    int guiZhouTotalHeal = doc1[29]["TotalHeal"].as<int>();
    int guiZhouTotalDead = doc1[29]["TotalDead"].as<int>();

    String ninXiaName = doc1[30]["name"].as<String>();
    int ninXiaTotalConfirm = doc1[30]["TotalConfirm"].as<int>();
    int ninXiaTotalHeal = doc1[30]["TotalHeal"].as<int>();
    int ninXiaTotalDead = doc1[30]["TotalDead"].as<int>();

    String aoMengName = doc1[31]["name"].as<String>();
    int aoMengTotalConfirm = doc1[31]["TotalConfirm"].as<int>();
    int aoMengTotalHeal = doc1[31]["TotalHeal"].as<int>();
    int aoMengTotalDead = doc1[31]["TotalDead"].as<int>();

    String qinHaiName = doc1[32]["name"].as<String>();
    int qinHaiTotalConfirm = doc1[32]["TotalConfirm"].as<int>();
    int qinHaiTotalHeal = doc1[32]["TotalHeal"].as<int>();
    int qinHaiTotalDead = doc1[32]["TotalDead"].as<int>();

    String xiZangName = doc1[33]["name"].as<String>();
    int xiZangTotalConfirm = doc1[33]["TotalConfirm"].as<int>();
    int xiZangTotalHeal = doc1[33]["TotalHeal"].as<int>();
    int xiZangTotalDead = doc1[33]["TotalDead"].as<int>();
    
    Serial.println(LocalExistingConfirm);
    Serial.println(ExistingConfirmInt);
    Serial.println(TotalConfirm);
    Serial.println(noSymptom);
    Serial.println(incrNoSymptom);
    Serial.println(inputTotal);
    Serial.println(inputIncrement);
    Serial.println(TotalDead);
    Serial.println(TotalDeadIncrement);
    Serial.println(AbroadExistingConfirm);
    Serial.println(AbroadConfirm);
    Serial.println(AbroadHeal);
    Serial.println(AbroadDead);
    Serial.println(Provinces);
    Serial.println(lastUpdateTime);
    Serial.println(xiZangName);
    Serial.println(xiZangTotalConfirm);
    Serial.println(xiZangTotalHeal);
    Serial.println(xiZangTotalDead);
    Serial.println(siChuanName);
    Serial.println(siChuanTotalConfirm);
    Serial.println(siChuanTotalHeal);
    Serial.println(siChuanTotalDead);
    Serial.println("开始发送吉林确诊数据......");
    char str4[100];
    sprintf(str4, "page0.n1.val=%d", jiLinTotalConfirm);
    TJC.print(str4);
    SendEnd();
    http.end();
  }
  delay(120000);
}





//
//#include<WiFi.h>
//#include<HTTPClient.h>
//#include<ArduinoJson.h>

//const char *ssid = "kenshin";
//const char *password = "123456789";

//void setup() {
//  Serial.begin(115200);
//  Serial.println("Serial init finish");
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.println(".");
//  }
//  Serial.println("WiFi connect finish!");
//  Serial.println("IP Address: ");
//  Serial.println(WiFi.localIP());
//}

//void loop() {
//  delay(2000);
//  char flag = 0;
//  if (flag == 0) {
//    Serial.println("进入了flag=0 开始发送请求");
//    HTTPClient http;
//    http.begin("http://192.168.100.187:3000/");
//    http.begin("http://192.168.204.187:3000/");
//    int httpCode = http.GET();
//    if ((httpCode = 200 || httpCode > 200) && httpCode < 300) {
//      Serial.println("状态码正确");
//      String payload = http.getString();
//      String json = payload;
//      DynamicJsonDocument doc(5000);
//      deserializeJson(doc, json);
//      int LocalExistingConfirm = doc["LocalExistingConfirm"].as<int>();
//      int ExistingConfirmInt = doc["ExistingConfirm"].as<int>();
//      int TotalConfirm = doc["TotalConfirm"].as<int>();
//      int noSymptom = doc["noSymptom"].as<int>();
//      int incrNoSymptom = doc["incrNoSymptom"].as<int>();
//      int inputTotal = doc["inputTotal"].as<int>();
//      int inputIncrement = doc["inputIncrement"].as<int>();
//      int TotalDead = doc["TotalDead"].as<int>();
//      int TotalDeadIncrement = doc["TotalDeadIncrement"].as<int>();
//      int AbroadExistingConfirm = doc["AbroadExistingConfirm"].as<int>();
//      int AbroadConfirm = doc["AbroadConfirm"].as<int>();
//      int AbroadHeal = doc["AbroadHeal"].as<int>();
//      int AbroadDead = doc["AbroadDead"].as<int>();
//      String lastUpdateTime = doc["lastUpdateTime"].as<String>();
//      String Provinces = doc["Provinces"].as<String>();

      //json数组的处理
//      DynamicJsonDocument doc1(5000);
//      deserializeJson(doc1, Provinces);
//      
//      String xiangGangName = doc1[0]["name"].as<String>();
//      int xiangGangTotalConfirm = doc1[0]["TotalConfirm"].as<int>();
//      int xiangGangTotalHeal = doc1[0]["TotalHeal"].as<int>();
//      int xiangGangTotalDead = doc1[0]["TotalDead"].as<int>();
//
//      String huBeiName = doc1[1]["name"].as<String>();
//      int huBeiTotalConfirm = doc1[1]["TotalConfirm"].as<int>();
//      int huBeiTotalHeal = doc1[1]["TotalHeal"].as<int>();
//      int huBeiTotalDead = doc1[1]["TotalDead"].as<int>();
//
//      String jiLinName = doc1[2]["name"].as<String>();
//      int jiLinTotalConfirm = doc1[2]["TotalConfirm"].as<int>();
//      int jiLinTotalHeal = doc1[2]["TotalHeal"].as<int>();
//      int jiLinTotalDead = doc1[2]["TotalDead"].as<int>();
//
//      String taiWanName = doc1[3]["name"].as<String>();
//      int taiWanTotalConfirm = doc1[3]["TotalConfirm"].as<int>();
//      int taiWanTotalHeal = doc1[3]["TotalHeal"].as<int>();
//      int taiWanTotalDead = doc1[3]["TotalDead"].as<int>();
//
//      String guangDongName = doc1[4]["name"].as<String>();
//      int guangDongTotalConfirm = doc1[4]["TotalConfirm"].as<int>();
//      int guangDongTotalHeal = doc1[4]["TotalHeal"].as<int>();
//      int guangDongTotalDead = doc1[4]["TotalDead"].as<int>();
//
//      String shangHaiName = doc1[5]["name"].as<String>();
//      int shangHaiTotalConfirm = doc1[5]["TotalConfirm"].as<int>();
//      int shangHaiTotalHeal = doc1[5]["TotalHeal"].as<int>();
//      int shangHaiTotalDead = doc1[5]["TotalDead"].as<int>();
//
//      String shanXi1Name = doc1[6]["name"].as<String>();
//      int shanXi1TotalConfirm = doc1[6]["TotalConfirm"].as<int>();
//      int shanXi1TotalHeal = doc1[6]["TotalHeal"].as<int>();
//      int shanXi1TotalDead = doc1[6]["TotalDead"].as<int>();
//
//      String heNanName = doc1[7]["name"].as<String>();
//      int heNanTotalConfirm = doc1[7]["TotalConfirm"].as<int>();
//      int heNanTotalHeal = doc1[7]["TotalHeal"].as<int>();
//      int heNanTotalDead = doc1[7]["TotalDead"].as<int>();
//
//      String fuJianName = doc1[8]["name"].as<String>();
//      int fuJianTotalConfirm = doc1[8]["TotalConfirm"].as<int>();
//      int fuJianTotalHeal = doc1[8]["TotalHeal"].as<int>();
//      int fuJianTotalDead = doc1[8]["TotalDead"].as<int>();
//
//      String zheJiangName = doc1[9]["name"].as<String>();
//      int zheJiangTotalConfirm = doc1[9]["TotalConfirm"].as<int>();
//      int zheJiangTotalHeal = doc1[9]["TotalHeal"].as<int>();
//      int zheJiangTotalDead = doc1[9]["TotalDead"].as<int>();
//
//      String shanDongName = doc1[10]["name"].as<String>();
//      int shanDongTotalConfirm = doc1[10]["TotalConfirm"].as<int>();
//      int shanDongTotalHeal = doc1[10]["TotalHeal"].as<int>();
//      int shanDongTotalDead = doc1[10]["TotalDead"].as<int>();
//
//      String heilongJiangName = doc1[11]["name"].as<String>();
//      int heilongJiangTotalConfirm = doc1[11]["TotalConfirm"].as<int>();
//      int heilongJiangTotalHeal = doc1[11]["TotalHeal"].as<int>();
//      int heilongJiangTotalDead = doc1[11]["TotalDead"].as<int>();
//
//      String yunNanName = doc1[12]["name"].as<String>();
//      int yunNanTotalConfirm = doc1[12]["TotalConfirm"].as<int>();
//      int yunNanTotalHeal = doc1[12]["TotalHeal"].as<int>();
//      int yunNanTotalDead = doc1[12]["TotalDead"].as<int>();
//
//      String jiangSuName = doc1[13]["name"].as<String>();
//      int jiangSuTotalConfirm = doc1[13]["TotalConfirm"].as<int>();
//      int jiangSuTotalHeal = doc1[13]["TotalHeal"].as<int>();
//      int jiangSuTotalDead = doc1[13]["TotalDead"].as<int>();
//
//      String heBeiName = doc1[14]["name"].as<String>();
//      int heBeiTotalConfirm = doc1[14]["TotalConfirm"].as<int>();
//      int heBeiTotalHeal = doc1[14]["TotalHeal"].as<int>();
//      int heBeiTotalDead = doc1[14]["TotalDead"].as<int>();
//
//      String tianJinName = doc1[15]["name"].as<String>();
//      int tianJinTotalConfirm = doc1[15]["TotalConfirm"].as<int>();
//      int tianJinTotalHeal = doc1[15]["TotalHeal"].as<int>();
//      int tianJinTotalDead = doc1[15]["TotalDead"].as<int>();
//
//      String beiJinName = doc1[16]["name"].as<String>();
//      int beiJinTotalConfirm = doc1[16]["TotalConfirm"].as<int>();
//      int beiJinTotalHeal = doc1[16]["TotalHeal"].as<int>();
//      int beiJinTotalDead = doc1[16]["TotalDead"].as<int>();
//
//      String neimengGuName = doc1[17]["name"].as<String>();
//      int neimengGuTotalConfirm = doc1[17]["TotalConfirm"].as<int>();
//      int neimengGuTotalHeal = doc1[17]["TotalHeal"].as<int>();
//      int neimengGuTotalDead = doc1[17]["TotalDead"].as<int>();
//
//      String siChuanName = doc1[18]["name"].as<String>();
//      int siChuanTotalConfirm = doc1[18]["TotalConfirm"].as<int>();
//      int siChuanTotalHeal = doc1[18]["TotalHeal"].as<int>();
//      int siChuanTotalDead = doc1[18]["TotalDead"].as<int>();
//
//      String liaoNinName = doc1[19]["name"].as<String>();
//      int liaoNinTotalConfirm = doc1[19]["TotalConfirm"].as<int>();
//      int liaoNinTotalHeal = doc1[19]["TotalHeal"].as<int>();
//      int liaoNinTotalDead = doc1[19]["TotalDead"].as<int>();
//
//      String guangXiName = doc1[20]["name"].as<String>();
//      int guangXiTotalConfirm = doc1[20]["TotalConfirm"].as<int>();
//      int guangXiTotalHeal = doc1[20]["TotalHeal"].as<int>();
//      int guangXiTotalDead = doc1[20]["TotalDead"].as<int>();
//
//      String huNanName = doc1[21]["name"].as<String>();
//      int huNanTotalConfirm = doc1[21]["TotalConfirm"].as<int>();
//      int huNanTotalHeal = doc1[21]["TotalHeal"].as<int>();
//      int huNanTotalDead = doc1[21]["TotalDead"].as<int>();
//
//      String jiangXiName = doc1[22]["name"].as<String>();
//      int jiangXiTotalConfirm = doc1[22]["TotalConfirm"].as<int>();
//      int jiangXiTotalHeal = doc1[22]["TotalHeal"].as<int>();
//      int jiangXiTotalDead = doc1[22]["TotalDead"].as<int>();
//
//      String anHuiName = doc1[23]["name"].as<String>();
//      int anHuiTotalConfirm = doc1[23]["TotalConfirm"].as<int>();
//      int anHuiTotalHeal = doc1[23]["TotalHeal"].as<int>();
//      int anHuiTotalDead = doc1[23]["TotalDead"].as<int>();
//
//      String xinJiangName = doc1[24]["name"].as<String>();
//      int xinJiangTotalConfirm = doc1[24]["TotalConfirm"].as<int>();
//      int xinJiangTotalHeal = doc1[24]["TotalHeal"].as<int>();
//      int xinJiangTotalDead = doc1[24]["TotalDead"].as<int>();
//
//      String chongQinName = doc1[25]["name"].as<String>();
//      int chongQinTotalConfirm = doc1[25]["TotalConfirm"].as<int>();
//      int chongQinTotalHeal = doc1[25]["TotalHeal"].as<int>();
//      int chongQinTotalDead = doc1[25]["TotalDead"].as<int>();
//
//      String ganSuName = doc1[26]["name"].as<String>();
//      int ganSuTotalConfirm = doc1[26]["TotalConfirm"].as<int>();
//      int ganSuTotalHeal = doc1[26]["TotalHeal"].as<int>();
//      int ganSuTotalDead = doc1[26]["TotalDead"].as<int>();
//
//      String shanXi2Name = doc1[27]["name"].as<String>();
//      int shanXi2TotalConfirm = doc1[27]["TotalConfirm"].as<int>();
//      int shanXi2TotalHeal = doc1[27]["TotalHeal"].as<int>();
//      int shanXi2TotalDead = doc1[27]["TotalDead"].as<int>();
//
//      String haiNanName = doc1[28]["name"].as<String>();
//      int haiNanTotalConfirm = doc1[28]["TotalConfirm"].as<int>();
//      int haiNanTotalHeal = doc1[28]["TotalHeal"].as<int>();
//      int haiNanTotalDead = doc1[28]["TotalDead"].as<int>();
//
//      String guiZhouName = doc1[29]["name"].as<String>();
//      int guiZhouTotalConfirm = doc1[29]["TotalConfirm"].as<int>();
//      int guiZhouTotalHeal = doc1[29]["TotalHeal"].as<int>();
//      int guiZhouTotalDead = doc1[29]["TotalDead"].as<int>();
//
//      String ninXiaName = doc1[30]["name"].as<String>();
//      int ninXiaTotalConfirm = doc1[30]["TotalConfirm"].as<int>();
//      int ninXiaTotalHeal = doc1[30]["TotalHeal"].as<int>();
//      int ninXiaTotalDead = doc1[30]["TotalDead"].as<int>();
//
//      String aoMengName = doc1[31]["name"].as<String>();
//      int aoMengTotalConfirm = doc1[31]["TotalConfirm"].as<int>();
//      int aoMengTotalHeal = doc1[31]["TotalHeal"].as<int>();
//      int aoMengTotalDead = doc1[31]["TotalDead"].as<int>();
//
//      String qinHaiName = doc1[32]["name"].as<String>();
//      int qinHaiTotalConfirm = doc1[32]["TotalConfirm"].as<int>();
//      int qinHaiTotalHeal = doc1[32]["TotalHeal"].as<int>();
//      int qinHaiTotalDead = doc1[32]["TotalDead"].as<int>();
//
//      String xiZangName = doc1[33]["name"].as<String>();
//      int xiZangTotalConfirm = doc1[33]["TotalConfirm"].as<int>();
//      int xiZangTotalHeal = doc1[33]["TotalHeal"].as<int>();
//      int xiZangTotalDead = doc1[33]["TotalDead"].as<int>();
//      
//      Serial.println(LocalExistingConfirm);
//      Serial.println(ExistingConfirmInt);
//      Serial.println(TotalConfirm);
//      Serial.println(noSymptom);
//      Serial.println(incrNoSymptom);
//      Serial.println(inputTotal);
//      Serial.println(inputIncrement);
//      Serial.println(TotalDead);
//      Serial.println(TotalDeadIncrement);
//      Serial.println(AbroadExistingConfirm);
//      Serial.println(AbroadConfirm);
//      Serial.println(AbroadHeal);
//      Serial.println(AbroadDead);
//      Serial.println(Provinces);
//      Serial.println(lastUpdateTime);
//      Serial.println(xiZangName);
//      Serial.println(xiZangTotalConfirm);
//      Serial.println(xiZangTotalHeal);
//      Serial.println(xiZangTotalDead);
//      Serial.println(siChuanName);
//      Serial.println(siChuanTotalConfirm);
//      Serial.println(siChuanTotalHeal);
//      Serial.println(siChuanTotalDead);
//      Serial.println(payload);
//      Serial.print("当前name是");
//      Serial.println(nameStr);
//      Serial.print("当前age是");
//      Serial.println(ageInt);
//      http.end();
//    }
//  }
//  delay(180000);
//}
