#include <iostream>

using namespace std;

int main() {
    int kg, n5;
    int sum = 0;
    cin >> kg;

    n5 = kg / 5;  // 5kg 봉지로 최대한 나눔

    // n5가 0보다 크거나 같을 때만 반복
    while (n5 >= 0) {
        // 나머지가 3kg으로 나누어 떨어지면
        if ((kg - n5 * 5) % 3 == 0) {
            sum = n5 + (kg - n5 * 5) / 3;  // 5kg과 3kg 봉지의 합
            cout << sum;
            return 0;
        }
        n5--;  // 나머지가 3으로 나누어지지 않으면 5kg 봉지 하나 줄임
    }

    // 5kg과 3kg으로 나눌 수 없을 때
    cout << -1;
    return 0;
}
