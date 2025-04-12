/*
#include<opencv2/opencv.hpp>

int main() {
	std::cout << "OpenCV Version:" << CV_VERSION;
}
*/

#include<opencv2/opencv.hpp>

int main() {
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	cv::imshow("lenna window", img);
	cv::waitKey(0);
}
