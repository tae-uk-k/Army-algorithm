#include <iostream>
#include <iomanip> 
using namespace std;

long long n, t = 1;
const long long MOD = 1000000000000;

void removeTrailingZeros() {
    while (t % 10 == 0) {
        t /= 10;
    }
}

int main() {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        t *= i;
        removeTrailingZeros();
        t %= MOD;
    }
    cout << setfill('0') << setw(5) << t % 100000 << endl;
    return 0;
}
