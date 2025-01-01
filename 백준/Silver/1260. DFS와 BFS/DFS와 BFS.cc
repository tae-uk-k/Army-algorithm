#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : graph[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

void dfs(const vector<vector<int>> &graph, int start, vector<bool> &visited) {
    visited[start] = true;
    cout << start << " ";

    for (int u : graph[start]) {
        if (!visited[u]) {
            dfs(graph, u, visited);
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(n + 1, false);
    dfs(graph, v, visited);
    cout << endl;

    bfs(graph, v);
    cout << endl;

    return 0;
}
