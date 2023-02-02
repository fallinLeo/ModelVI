#include "arduino.h"
class Function
{
private:
	int sensorValue;
	const int SIZE = 5;
	float EMA_S_pre = 0, volts, volts_dirt, ir_distance, ir_dis, sum;
	float EMA_a = 0.2;
	int EMA_S = 0;
	int buffer[5];
public:
	float Filter(int);
};

float Function::Filter(int A)
{
	sensorValue = A;
	EMA_S_pre = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S_pre);   //필터링 수식을 통해 필터링 된 센서값 도출(EMA_S_pre)

  //이동평균 필터 적용////////////////////////////

	sum -= buffer[0];
	for (int i = 0; i < SIZE - 1; i++)

	{

		buffer[i] = buffer[i + 1];

	}

	buffer[SIZE - 1] = EMA_S_pre;

	sum += buffer[SIZE - 1];

	EMA_S = sum / SIZE + 2;//이동평균필터를 통해 최종 필터링한 센서값 도출(EMA_S)

	////////////////////////////////


	volts = (EMA_S) * 5.0 / 1023.0;

	ir_distance = 604.95 * pow(volts, -1.1904);//필터링된 거리값 도출

	ir_distance = volts * 10;
	return ir_distance;
}
