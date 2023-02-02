#include "arduino.h"
//=======motor run function start=====

const int AIA = 11;  //LEFT_ROLLER DIRECTION
const int AIB = 6;   //LEFT_ROLLER VELOCITY
const int BIA = 3;   //RIGHT_ROLLER DIRECTION
const int BIB = 5;   //RIGHT_ROLLER VELOCITY
int Max_speed1 = 200; //forward speed
int Max_speed2 = 180; //turn speed
void forward() {
	analogWrite(AIA, 0);
	analogWrite(AIB, Max_speed1 + 20);
	analogWrite(BIA, 0);
	analogWrite(BIB, Max_speed1);
}

void right(float t) {
	analogWrite(AIA, 0);
	analogWrite(AIB, Max_speed2);
	analogWrite(BIA, Max_speed2);
	analogWrite(BIB, 0);
	delay(t);
}

void left(float t) {
	analogWrite(AIA, Max_speed2);
	analogWrite(AIB, 0);
	analogWrite(BIA, 0);
	analogWrite(BIB, Max_speed2);
	delay(t);

}

void Brake(float t) {
	analogWrite(AIA, 0);
	analogWrite(AIB, 0);
	analogWrite(BIA, 0);
	analogWrite(BIB, 0);
	delay(t);
}
void Right(float t) {
	analogWrite(AIA, 0);
	analogWrite(AIB, 0);
	analogWrite(BIA, Max_speed2);
	analogWrite(BIB, 0);
	delay(t);

}

void Left(float t) {
	analogWrite(AIA, Max_speed2 - 20);
	analogWrite(AIB, 0);
	analogWrite(BIA, 0);
	analogWrite(BIB, 0);
	delay(t);

}

void brake() {
	analogWrite(AIA, 0);
	analogWrite(AIB, 0);
	analogWrite(BIA, 0);
	analogWrite(BIB, 0);
}
//======motor run function end====
