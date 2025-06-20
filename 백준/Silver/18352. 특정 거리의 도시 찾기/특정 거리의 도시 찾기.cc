#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[X] = 0;
    q.push(X);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) result.push_back(i);
    }
    if (result.empty()) {
        cout << -1;
    } else {
        sort(result.begin(), result.end());
        for (int city : result) {
            cout << city << "\n";
        }
    }
    return 0;
}
