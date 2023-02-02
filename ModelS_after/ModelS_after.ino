#include <Servo.h>
#include <math.h>
#include <SoftwareSerial.h>
#include "motor.cpp"
#include "Function.cpp"

SoftwareSerial s(7,8);    // 7:RX 8:TX

int psd1 = A0;
int psd2 = A1;
int psd3 = A2; //psd센서 정의
long first1=millis();
long first2=millis();
long last1,last2;
int adelt;
float F_Dist, L_Dist, R_Dist; //Front dist,Left dist, Right dist, L45, R45
float F_Sensor,R_Sensor,L_Sensor;
const int Dist_Min = 27; //Minimum distance Front, L45,R45
const int LR_Dist_Min = 31; //Minumum distance L,R 
float delay_t = 130; //car tunning delay time

Function F_f;
Function L_f;
Function R_f;

float Rotate_t() { //find delta and delaytime algorithm(incomplete)
  float delta;
  float delaytime;
  F_Sensor = -2.3643*F_Dist+82.955;
  L_Sensor = -1.9531*L_Dist+71.252;
  R_Sensor = -1.7966*R_Dist+66.825;
  if(L_Sensor<R_Sensor)
  {
    delta = atan(L_Sensor/(1.4142135*F_Sensor-L_Sensor));
    delaytime = delta * 200*180/(30*3.141592);
    delaytime = constrain(delaytime,-120,120);
  }
  else if(L_Sensor>R_Sensor)
  {
    delta = atan(R_Sensor/(1.4142135*F_Sensor-R_Sensor));
    delaytime = delta * 200*180/(30*3.141592);
    delaytime = constrain(delaytime,-120,120);
    
  }
  else
  {
    delaytime = 120;
  }
  adelt=abs(delaytime);
  return adelt;
}
void setup() {
  Serial.begin(9600);
  s.begin(9600);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(psd1,INPUT);
  pinMode(psd2,INPUT);
  pinMode(psd3,INPUT);
  
}



void loop() {
  
  last1=millis();
  last2=millis();
  delay_t=Rotate_t();
  F_Dist=F_f.Filter(analogRead(psd1));
  R_Dist=R_f.Filter(analogRead(psd2));
  L_Dist=L_f.Filter(analogRead(psd3));
  Sensor_print();
  //Servowrite();
  //forward();
  //Look_brake();
  
}



void Sensor_print()
{
  if(last1-first1==1000)
  {
    Serial.print("Front Sensor : ");
    Serial.println(F_Dist);
    Serial.print("R45_SENSOR : ");
    Serial.println(R_Dist);
    Serial.print("L45_Sensor : ");
    Serial.println(L_Dist);
    //Serial.println(delay_t);
    first1=last1;
  }
}

void Servowrite()
{
  //s.write('s');

  if(R_Dist>LR_Dist_Min)                               
  {
    s.write('l');
  }
  if(L_Dist>LR_Dist_Min)
  {
    s.write('e');
  }
  if(F_Dist>Dist_Min)
  {
    s.write('s');
  }
  

}
void Look_brake()
{
  if(R_Dist>LR_Dist_Min)                               
  {
    //brake();
    s.write('e');
    Left(delay_t);
  }
  if(L_Dist>LR_Dist_Min)
  {
    //brake();
    s.write('t');
    Right(delay_t);
    
  }
  if(F_Dist>Dist_Min)
  {
    s.write('t');
    Brake(delay_t);
    if (L_Dist < R_Dist && L_Dist < F_Dist)
      {
        //s.write('e');
        Left(delay_t);
      }
      else if (R_Dist < L_Dist && R_Dist < F_Dist)
      {
        //s.write('t');
        Right(delay_t);
      }
  }
  
}