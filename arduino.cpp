#include <iostream>
#include "arduino.h""


typedef enum { OFF, ON } STATE;
class Blinker {
    byte pin;
    STATE state;
    int onTime, offTime;
    uint32_t prevMillis;
public:
    Blinker(int pinN, long onT, long offT);
    void update();
};

Blinker::Blinker(int pinN, long onT, long offT) {  	// ������
	pin = pinN;
	pinMode(pin, OUTPUT);
	onTime = onT; offTime = offT;
	state = OFF;  prevMillis = millis();
}

void Blinker::update() {                  // �ֱ��� ȣ�� �ʿ�
    unsigned long curMillis = millis();
    if (state == ON) {
        if (curMillis - prevMillis >= onTime) {
            state = OFF;
            prevMillis = curMillis;
            digitalWrite(pin, state);
        }
    }
    else {
        if (curMillis - prevMillis >= offTime) {
            state = ON;
            prevMillis = curMillis;
            digitalWrite(pin, state);
        }
    }
}
