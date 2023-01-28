#include <iostream>
#include <cmath>
using namespace std;
void KalmanFilter(double measurement, double& prediction, double& P, double Q, double R) {
    // Time update
    prediction = prediction;
    P = P + Q;

    // Measurement update
    double K = P / (P + R);
    prediction = prediction + K * (measurement - prediction);
    P = (1 - K) * P;
}

int main(void)
{
    double prediction = 0;
    double P = 1;
    KalmanFilter(20,prediction, P, 0.1, 1);
    cout << prediction << endl;
    return 0;

}
