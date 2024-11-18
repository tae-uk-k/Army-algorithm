#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int diagonal = 1; // 현재 대각선 번호
    int sum = 0;      // 현재까지의 분수 개수 합

    // X번째 분수가 포함된 대각선 찾기
    while (sum + diagonal < X) {
        sum += diagonal;
        diagonal++;
    }

    // 대각선에서의 위치 계산
    int offset = X - sum;
    int numerator, denominator;

    if (diagonal % 2 == 1) {
        // 대각선이 홀수: 분자가 감소하고 분모가 증가
        numerator = diagonal - offset + 1;
        denominator = offset;
    } else {
        // 대각선이 짝수: 분자가 증가하고 분모가 감소
        numerator = offset;
        denominator = diagonal - offset + 1;
    }

    cout << numerator << '/' << denominator;
    return 0;
}
