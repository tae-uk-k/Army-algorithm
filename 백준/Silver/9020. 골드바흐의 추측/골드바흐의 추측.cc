#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> prime;
    unordered_map<int, int> prime_idx;
    vector<bool> is_prime(10001, true);
    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 10000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 10000; i++) {
        if (is_prime[i]) {
            prime_idx[i] = prime.size();
            prime.push_back(i);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a = n / 2;
        while (a > 0) {
            if (prime_idx.find(a) != prime_idx.end() && prime_idx.find(n - a) != prime_idx.end()) {
                cout << a << ' ' << n - a << '\n';
                break;
            }
            a--;
        }
    }

    return 0;
}
