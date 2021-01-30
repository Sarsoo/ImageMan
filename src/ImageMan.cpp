// ImageMan.cpp : Defines the entry point for the application.
//

#include "ImageMan/ImageMan.hpp"

using namespace std;
using namespace cv;

void Resize(Mat &image, int height, int width)
{
	resize(image, image, cv::Size(height, width), INTER_AREA);
}

void SobelFilter(Mat image, int dx = 1, int dy = 0)
{
	Sobel(image, image, -1, dx, dy);
}

void Blur(Mat image)
{
	GaussianBlur(image, image, Size(17, 17), 3.0, 3.0);
}

void Dilate(Mat image, int dilation_size = 5)
{
	Mat element = getStructuringElement(MORPH_RECT,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));
	dilate(image, image, element);
}

int main()
{
	Mat clouds = imread("clouds.jpg");
	Mat holo = imread("holoshot.png");
	cout << "image size: (" << holo.size() << ")" << endl;
	try {
		//SobelFilter(holo);
		Dilate(holo);
		Blur(holo);

		Resize(clouds, 800, 400);
		SobelFilter(clouds, 0, 1);
		Dilate(clouds);
	
		imshow("holo", holo);
		imshow("clouds", clouds);
		waitKey();
	}
	catch (cv::Exception e) {
		cout << "error: " << e.what() << endl;
	}
	return 0;
}
