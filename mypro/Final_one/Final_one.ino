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
    delay(3500);
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
    int timeYear = doc["timeYear"].as<int>();
    int timeMonth = doc["timeMonth"].as<int>();
    int timeDay = doc["timeDay"].as<int>();
    int timeHour = doc["timeHour"].as<int>();
    int timeMinute = doc["timeMinute"].as<int>();
    int timeSecond = doc["timeSecond"].as<int>();
    int hourDiffs = doc["hourDiffs"].as<int>();
    int minuteDiffs = doc["minuteDiffs"].as<int>();
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
    char str5[100];
    char str6[100];
    char str7[100];
    char str8[100];
    char str9[100];
    char str10[100];
    char str11[100];
    char str12[100];
    char str13[100];
    char str14[100];
    char str15[100];
    char str16[100];
    char str17[100];
    char str18[100];
    char str19[100];
    char str20[100];
    char str21[100];
    char str22[20];
    char str23[20];
    char str24[20];
    char str25[20];
    char str26[20];
    char str27[20];
    char str28[20];
    char str29[20];
    char hubei1[100];
    char hubei2[100];
    char hubei3[100];
    char jilin1[100];
    char jilin2[100];
    char jilin3[100];
    char taiwan1[100];
    char taiwan2[100];
    char taiwan3[100];
    char guangdong1[100];
    char guangdong2[100];
    char guangdong3[100];
    char shanxi1[100];
    char shanxi2[100];
    char shanxi3[100];
    char heilongjiang1[100];
    char heilongjiang2[100];
    char heilongjiang3[100];
    sprintf(str4, "page0.n0.val=%d", LocalExistingConfirm);
    sprintf(str5, "page0.n1.val=%d", ExistingConfirmInt);
    sprintf(str6, "page0.n2.val=%d", TotalConfirm);
    sprintf(str7, "page0.n3.val=%d", noSymptom);
    sprintf(str8, "page0.n4.val=%d", inputTotal);
    sprintf(str9, "page0.n5.val=%d", TotalDead);
    sprintf(str10, "page1.n0.val=%d", AbroadExistingConfirm);
    sprintf(str11, "page1.n1.val=%d", AbroadConfirm);
    sprintf(str12, "page1.n2.val=%d", AbroadHeal);
    sprintf(str13, "page1.n3.val=%d", AbroadDead);
    sprintf(str14, "page0.n6.val=%d", timeYear);
    sprintf(str15, "page0.n7.val=%d", timeMonth);
    sprintf(str16, "page0.n8.val=%d", timeDay);
    sprintf(str17, "page0.n9.val=%d", timeHour);
    sprintf(str18, "page0.n10.val=%d", timeMinute);
    sprintf(str19, "page0.n11.val=%d", timeSecond);
    sprintf(str20, "page0.n12.val=%d", hourDiffs);
    sprintf(str21, "page0.n13.val=%d", minuteDiffs);

    sprintf(str22, "page1.n6.val=%d", timeYear);
    sprintf(str23, "page1.n7.val=%d", timeMonth);
    sprintf(str24, "page1.n8.val=%d", timeDay);
    sprintf(str25, "page1.n9.val=%d", timeHour);
    sprintf(str26, "page1.n10.val=%d", timeMinute);
    sprintf(str27, "page1.n11.val=%d", timeSecond);
    sprintf(str28, "page1.n12.val=%d", hourDiffs);
    sprintf(str29, "page1.n13.val=%d", minuteDiffs);
 
    sprintf(hubei1, "page3.n0.val=%d", huBeiTotalHeal);
    sprintf(hubei2, "page3.n1.val=%d", huBeiTotalConfirm);
    sprintf(hubei3, "page3.n2.val=%d", huBeiTotalDead);

    sprintf(jilin1, "page3.n3.val=%d", jiLinTotalHeal);
    sprintf(jilin2, "page3.n8.val=%d", jiLinTotalConfirm);
    sprintf(jilin3, "page3.n9.val=%d", jiLinTotalDead);

    sprintf(taiwan1, "page3.n4.val=%d", taiWanTotalHeal);
    sprintf(taiwan2, "page3.n10.val=%d", taiWanTotalConfirm);
    sprintf(taiwan3, "page3.n11.val=%d", taiWanTotalDead);

    sprintf(guangdong1, "page3.n5.val=%d", guangDongTotalHeal);
    sprintf(guangdong2, "page3.n12.val=%d", guangDongTotalConfirm);
    sprintf(guangdong3, "page3.n13.val=%d", guangDongTotalDead);

    sprintf(shanxi1, "page3.n6.val=%d", shanXi1TotalHeal);
    sprintf(shanxi2, "page3.n14.val=%d", shanXi1TotalConfirm);
    sprintf(shanxi3, "page3.n15.val=%d", shanXi1TotalDead);

    sprintf(heilongjiang1, "page3.n7.val=%d", heilongJiangTotalHeal);
    sprintf(heilongjiang2, "page3.n16.val=%d", heilongJiangTotalConfirm);
    sprintf(heilongjiang3, "page3.n17.val=%d", heilongJiangTotalDead);

    TJC.print(str4);
    SendEnd();
    TJC.print(str5);
    SendEnd();
    TJC.print(str6);
    SendEnd();
    TJC.print(str7);
    SendEnd();
    TJC.print(str8);
    SendEnd();
    TJC.print(str9);
    SendEnd();
    TJC.print(str10);
    SendEnd();
    TJC.print(str11);
    SendEnd();
    TJC.print(str12);
    SendEnd();
    TJC.print(str13);
    SendEnd();
    TJC.print(str14);
    SendEnd();
    TJC.print(str15);
    SendEnd();
    TJC.print(str16);
    SendEnd();
    TJC.print(str17);
    SendEnd();
    TJC.print(str18);
    SendEnd();
    TJC.print(str19);
    SendEnd();
    TJC.print(str20);
    SendEnd();
    TJC.print(str21);
    SendEnd();
    TJC.print(str22);
    SendEnd();
    TJC.print(str23);
    SendEnd();
    TJC.print(str24);
    SendEnd();
    TJC.print(str25);
    SendEnd();
    TJC.print(str26);
    SendEnd();
    TJC.print(str27);
    SendEnd();
    TJC.print(str28);
    SendEnd();
    TJC.print(str29);
    SendEnd();
    TJC.print(hubei1);
    SendEnd();
    TJC.print(hubei2);
    SendEnd();
    TJC.print(hubei3);
    SendEnd();

    TJC.print(jilin1);
    SendEnd();
    TJC.print(jilin2);
    SendEnd();
    TJC.print(jilin3);
    SendEnd();

    TJC.print(taiwan1);
    SendEnd();
    TJC.print(taiwan2);
    SendEnd();
    TJC.print(taiwan3);
    SendEnd();

    TJC.print(guangdong1);
    SendEnd();
    TJC.print(guangdong2);
    SendEnd();
    TJC.print(guangdong3);
    SendEnd();

    TJC.print(shanxi1);
    SendEnd();
    TJC.print(shanxi2);
    SendEnd();
    TJC.print(shanxi3);
    SendEnd();

    TJC.print(heilongjiang1);
    SendEnd();
    TJC.print(heilongjiang2);
    SendEnd();
    TJC.print(heilongjiang3);
    SendEnd();
    
    http.end();
  }
  delay(120000);
}
