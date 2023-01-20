#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img_frame;
	
	
	VideoCapture cap(0);
	
	
	if (!cap.isOpened())
	{
		cout << "카메라 불가능" << endl;
		return -1;
	}
	while (1)
	{
		bool ret = cap.read(img_frame);
		
		
		if (!ret)
		{
			cout << "캡처 실패" << endl;
			break;
			return -1;
		}

		int height = img_frame.rows;
		int width = img_frame.cols;
		Mat img_gray(height, width, CV_8UC1);
		float x_sta, x_end, y_sta, y_end;
		x_sta = 20;x_end = 300;y_sta = 20;y_end = 300;
		for (int y = 0;y < height;y++)
		{
			uchar* pointer_input = img_frame.ptr<uchar>(y);
			uchar* pointer_output = img_gray.ptr<uchar>(y);
			for (int x = 0;x < width;x++)
			{
				uchar b = pointer_input[x * 3 + 0];
				uchar g = pointer_input[x * 3 + 1];
				uchar r = pointer_input[x * 3 + 2];
				if (y>y_sta&&y<y_end)
				{
					if (x > x_sta && x < x_end)
					{
						pointer_input[x * 3 + 0] = 0;
						pointer_input[x * 3 + 1] = 255;
						pointer_input[x * 3 + 2] = 0;
					}
				}
				
				pointer_output[x] = r * 0.2126 + g * 0.7152 + b * 0.0722;
			}
		}
		//Mat img_result;
		//cvtColor(img_gray, img_result, COLOR_GRAY2BGR);
		
		
				
		imshow("std", img_frame);
		imshow("Video", img_gray);
		int key = waitKey(1);
		if (key == 27)
		{

			cap.release();
			return 0;
		}
	}


	
}