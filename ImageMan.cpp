// ImageMan.cpp : Defines the entry point for the application.
//

#include "ImageMan.h"

using namespace std;
using namespace cv;

int main()
{
	//Mat image = imread("clouds.jpg");
	Mat image = imread("holoshot.png");
	cout << "image size: (" << image.size() << ")" << endl;
	try {
		//resize(image, image, cv::Size(1000, 1000), INTER_AREA);
		GaussianBlur(image, image, Size(17, 17), 3.0, 3.0);
		//Sobel(image, image, -1, 1, 1);
	
		imshow("image", image);
		waitKey();
	}
	catch (cv::Exception e) {
		cout << "error: " << e.what() << endl;
	}
	return 0;
}
