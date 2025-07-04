#include <bits/stdc++.h>
using namespace std;
int n, g, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1), level(n+1);

    for (int i = 0; i < n - 1; i++) {
        cin >> g >> s;
        adj[g].push_back(s);
        adj[s].push_back(g);
    }

    int m;
    cin >> m;
    vector<pair<int,int>> qs(m);
    for (int i = 0; i < m; i++) {
        cin >> qs[i].first >> qs[i].second;
    }

    queue<int> qu;
    qu.push(1);
    parent[1] = 0;
    level[1] = 1;
    while (!qu.empty()) {
        int node = qu.front(); qu.pop();
        for (int nei : adj[node]) {
            if (nei == parent[node]) continue;
            parent[nei] = node;
            level[nei] = level[node] + 1;
            qu.push(nei);
        }
    }

    for (auto &q : qs) {
        int a = q.first, b = q.second;
        if (level[a] < level[b]) swap(a, b);
        while (level[a] != level[b]) a = parent[a];
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << "\n";
    }

    return 0;
}
