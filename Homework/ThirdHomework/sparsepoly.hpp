#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>
using namespace std;

#define MAX_DEGREE 101 // 최대 차수 정의 (예: 0~100)

class SparsePoly {
    int numTerms;                        // 항의 개수
    vector<int> exponents;              // 차수 저장 벡터
    vector<float> coefficients;         // 계수 저장 벡터

public:
    // 생성자
    SparsePoly() : numTerms(0) {}

    // 다항식 입력 함수
    void read() {
        cout << "항의 개수를 입력하세요: ";
        cin >> numTerms;

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ";
            cin >> coefficients[i] >> exponents[i];
        }
    }

    // 다항식 출력 함수
    void display(const char* str) {
        cout << str;
        for (int i = 0; i < numTerms; ++i) {
            cout << coefficients[i] << "x^" << exponents[i];
            if (i != numTerms - 1) cout << " + ";
        }
        cout << endl;
    }

    // 다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] > b.exponents[j]) {
                coefficients.push_back(a.coefficients[i]);
                exponents.push_back(a.exponents[i]);
                ++i;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                coefficients.push_back(b.coefficients[j]);
                exponents.push_back(b.exponents[j]);
                ++j;
            }
            else {
                float sumCoeff = a.coefficients[i] + b.coefficients[j];
                if (sumCoeff != 0) {
                    coefficients.push_back(sumCoeff);
                    exponents.push_back(a.exponents[i]);
                }
                ++i;
                ++j;
            }
        }

        // 남은 항들 추가
        while (i < a.numTerms) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            ++i;
        }
        while (j < b.numTerms) {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            ++j;
        }

        numTerms = coefficients.size();
    }
};

#endif
