#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio> 
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
    int n;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &n);

    int arr[100]; 
    printf("%d개의 배열 값을 입력하세요: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int maxValue = getMaxValue(arr, n);
    printf("최댓값: %d\n", maxValue);

    return 0;
}

