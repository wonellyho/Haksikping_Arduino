// ���� �ʹ� �������� ����

// �ø��� ���â���� AT ��ɾ ���� �������� ������ Ȯ���ϴ� �ڵ�
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //RX, TX

void setup() {
    Serial.begin(9600); // ���巹��Ʈ ��żӵ� 9600
    mySerial.begin(9600);
}

void loop() {

    if (mySerial.available())
    {
        Serial.write(mySerial.read());
        // ����Ʈ���� �ø����� ���� ���� �����͸� �ø��� ����Ϳ� ǥ��
    }
    if (Serial.available())
    {
        mySerial.write(Serial.read());
        // ��, �ø��� ����͸� ���� �Է��� �����͸� ����Ʈ���� �ø���� ����
    }
}

// AT+CWLAP: ��ɾ ����, 2.4GHz�� ������������ ��ȣ�� �����Ѵ�.(�ڵ��� �ֽ��� 2.4GHz)
// AT + CWJAP = "SSID", "��й�ȣ"
