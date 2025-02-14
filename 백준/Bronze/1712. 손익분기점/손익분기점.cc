#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    if (C <= B) cout << -1;
    else cout << A / (C - B) + 1;
}
