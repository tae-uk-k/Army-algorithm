#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& Edge, int visited[], int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : Edge[cur]) {
            if (visited[next] != 0 && visited[cur] == visited[next]) {
                return false;
            }
            if (visited[next] == 0) {
                visited[next] = visited[cur] * -1;
                q.push(next);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int V, E, v, u;
        cin >> V >> E;
        vector<vector<int>> Edge(V + 1);
        int visited[20001] = {0};
        
        for (int j = 0; j < E; j++) {
            cin >> v >> u;
            Edge[v].push_back(u);
            Edge[u].push_back(v);
        }

        bool isBipartite = true;
        for (int k = 1; k <= V; k++) {
            if (visited[k] == 0) {
                if (!bfs(Edge, visited, k)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << "\n";
    }
    return 0;
}
