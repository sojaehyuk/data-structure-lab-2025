#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat image = imread("Lenna.png", IMREAD_COLOR);
    if (image.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
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

    cout << "�ִ� ȭ�� ���: " << maxBrightness << endl;
    return 0;
}

