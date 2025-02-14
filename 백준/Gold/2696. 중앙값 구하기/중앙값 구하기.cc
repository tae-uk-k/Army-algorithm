#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> res;
        priority_queue<ll> left;
        priority_queue<ll, vector<ll>, greater<ll>> right;
        for (int i = 1; i <= N; i++) {
            cin >> x;
            if (i % 2) {
                left.push(x);
                if (!left.empty() && !right.empty() && left.top() > right.top()) {
                    right.push(left.top());
                    left.pop();
                    left.push(right.top());
                    right.pop();
                }
            } else {
                right.push(x);
            }
            if (i % 2) res.push_back(left.top());
        }
        cout << res.size() << "\n";
        for (ll v : res) cout << v << " ";
        cout << "\n";
    }
}
