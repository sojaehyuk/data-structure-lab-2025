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
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &n);

    int arr[100]; 
    printf("%d���� �迭 ���� �Է��ϼ���: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int maxValue = getMaxValue(arr, n);
    printf("�ִ�: %d\n", maxValue);

    return 0;
}

