#include <bits/stdc++.h>
using namespace std;

int N, K;
int loc[100001];

int bfs() {
    loc[N] = 0;
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        if (a == K) return loc[a];

        if (a - 1 >= 0 && loc[a - 1] == -1) {
            loc[a - 1] = loc[a] + 1;
            q.push(a - 1);
        }
        if (a + 1 <= 100000 && loc[a + 1] == -1) {
            loc[a + 1] = loc[a] + 1;
            q.push(a + 1);
        }
        if (2 * a <= 100000 && loc[2 * a] == -1) {
            loc[2 * a] = loc[a] + 1;
            q.push(2 * a);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    fill(loc, loc + 100001, -1);
    cin >> N >> K;
    cout << bfs();
    return 0;
}
