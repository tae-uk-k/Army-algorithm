#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    
    vector<tuple<int, int, int>> v(N);
    
    for (int i = 0; i < N; i++) {
        int h, w;
        cin >> h >> w;
        v[i] = {h, w, 0};
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j])) {
                get<2>(v[i])++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << get<2>(v[i]) + 1 << ' ';
    }
}
