#include <iostream>
using namespace std;

int getMaxValue(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // 예시 배열들
    int arr1[] = { 3, 7, 2, 9, 10, 5 };
    int arr2[] = { -10, -5, -3 };
    int arr3[] = { 100, 200, 300, 50, 400 };
    int arr4[] = { 0, 0, -2, 0 };
    int arr5[] = { 10000 };

    // 결과 출력
    cout << getMaxValue(arr1, 6) << endl;  // 10
    cout << getMaxValue(arr2, 3) << endl;  // -3
    cout << getMaxValue(arr3, 5) << endl;  // 400
    cout << getMaxValue(arr4, 4) << endl;  // 0
    cout << getMaxValue(arr5, 1) << endl;  // 10000

    return 0;
}
