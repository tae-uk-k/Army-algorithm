#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : E[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int x : ans) {
        cout << x << ' ';
    }
        


    return 0;
}
