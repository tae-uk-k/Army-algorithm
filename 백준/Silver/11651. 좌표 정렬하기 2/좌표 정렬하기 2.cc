#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    
    vector<pair<int, int>> v(N);
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {y, x};
    }

    sort(v.begin(), v.end());

    for (auto &[y, x] : v) {
        cout << x << ' ' << y << '\n';
    }
}
