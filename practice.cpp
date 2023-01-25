#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img_color;
	img_color = imread("Lenna.png", IMREAD_COLOR);
	if (img_color.empty())
	{
		cout << "이미지 파일을 읽어올 수 없습니다." << endl;
		return -1;
	}
	Mat img_gray;
	cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

	Mat img_binary;
	threshold(img_gray, img_binary, 127, 255, THRESH_BINARY);

	imshow("Grayscale", img_gray);
	imshow("Binary", img_binary);
	waitKey(0);
}