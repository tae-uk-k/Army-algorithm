#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    stack<int> s;
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top() <= heights[i]) {
            s.pop();
        }
        sum += s.size();
        s.push(heights[i]);
    }

    cout << sum;
    return 0;
}
