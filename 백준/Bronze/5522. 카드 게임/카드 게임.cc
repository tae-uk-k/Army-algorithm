#include <iostream>
using namespace std;

int main() {
    int sum = 0, score;

    for (int i = 0; i < 5; ++i) {
        cin >> score;
        sum += score;
    }

    cout << sum << endl;

    return 0;
}