// 제일 초반 와이파이 세팅

// 시리얼 통신창에서 AT 명령어를 통해 와이파이 연결을 확인하는 코드
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //RX, TX

void setup() {
    Serial.begin(9600); // 보드레이트 통신속도 9600
    mySerial.begin(9600);
}

void loop() {

    if (mySerial.available())
    {
        Serial.write(mySerial.read());
        // 소프트웨어 시리얼을 통해 받은 데이터를 시리얼 모니터에 표시
    }
    if (Serial.available())
    {
        mySerial.write(Serial.read());
        // 즉, 시리얼 모니터를 통해 입력한 데이터를 소프트웨어 시리얼로 전송
    }
}

// AT+CWLAP: 명령어를 통해, 2.4GHz의 무선와이파이 신호와 연결한다.(핸드폰 핫스팟 2.4GHz)
// AT + CWJAP = "SSID", "비밀번호"
