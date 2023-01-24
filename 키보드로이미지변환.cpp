#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img_frame;

    img_frame = imread("Lenna.png", IMREAD_COLOR);
    int step = 1;
    while (1)
    {
        Mat img_result;
        if (step == 1)
        {
            //cvtColor(img_result, img_frame, IMREAD_COLOR);
            imshow("result", img_frame);

        }
        else if (step > 1)
        {
            cvtColor(img_frame, img_result, COLOR_BGR2GRAY);

            if (step > 2)
            {
                Canny(img_frame, img_result, 50, 150);
            }
            imshow("result", img_result);
        }

        int Key = waitKey(1);
        if (Key == 27)
        {
            break;
        }
        else if (Key == 49)
        {
            step = 1;
        }
        else if (Key == 50)
        {
            step = 2;
        }
        else if (Key == 51)
        {
            step = 3;
        }
    }
    return 0;
}
