#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat image = imread("Lenna.png", IMREAD_COLOR);
    if (image.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }

    int maxBrightness = 0;

    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            Vec3b pixel = image.at<Vec3b>(y, x);
            int brightness = max({ pixel[0], pixel[1], pixel[2] });
            maxBrightness = max(maxBrightness, brightness);
        }
    }

    cout << "최대 화소 밝기: " << maxBrightness << endl;
    return 0;
}

