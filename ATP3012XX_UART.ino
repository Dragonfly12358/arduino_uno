#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 7);  // 3->D8, 2->D7

// Program is interrupted when the length of 'str' is large.
String str[] = 
{
  "dennwaba'nngo-wa <NUM VAL=01-2345-6789>desu. ",
  "sa-ba-;<NUM VAL=3512>no/ha-dodhi'_su_kuni e'ra-+haxtuse-. ",
  "getuyo'-no/<NUMK VAL=21 COUNTER=di>kara <NUMK VAL=8 COUNTER=cha'nnneru>de/yoyaku+sima'sita. ",
  "ryo'-kinnwa;<NUMK VAL=550 COUNTER=enn>desu. ",
  "sumimase'nn <NUMK VAL=10 COUNTER=funn>+okurema'su.",
  "<NUMK VAL=20 COUNTER=funn>ni e'kide/ma'xtutemasu. ",
  "asunote'nnki to-kyo- hare'noti+kumori saiko-ki'onn <NUMK VAL=25 COUNTER=do>. ",
  "<NUMK VAL=100 COUNTER=me'-toru>saki ko-ennirigutino/ko-satenno+hidaride'su. ",
  "konosaki;<NUMK VAL=3 COUNTER=kiro>/ju-taichu-.tu-kadi'kann; ",
  "yorosi'idesuka?",
  // "koredei'i? ",
  // "baxtuteri-no/ju-denn+kannryo-. ",
  // "<NUMK VAL=2006 COUNTER=nenn> <NUMK VAL=1 COUNTER=gatu>;<NUMK VAL=15 COUNTER=niti>. ",
  // "<NUMK VAL=16 COUNTER=di>;<NUMK VAL=5 COUNTER=funn>/<NUMK VAL=35 COUNTER=byo->desu. ",
  // "bakuonnga ginnse'kaino/ko-gennni/hirogaru. "
};

int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("connected");
  mySerial.begin(9600);
  mySerial.println("setuzoku.");
  while(mySerial.read() != '>') {}
}

void loop() {
  for(i=0; i<10; i++) {
    mySerial.println(str[i]);  // asynchronous processing 
    Serial.println(i);
    mySerial.listen();
    while(mySerial.read() != 62) {
      delay(1000);
    }
  }
}
