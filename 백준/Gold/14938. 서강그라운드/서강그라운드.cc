#include <bits/stdc++.h>
using namespace std;

int n, m, r, t;
int node[101]; 
int Max = 0;
const int INF = 987654321;
vector<vector<int>> graph;

void ds(int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int next = 1; next <= n; next++) {
            if (graph[cur][next] == INF) continue;

            int nextCost = cost + graph[cur][next];
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    int sum = 0;
    for (int a = 1; a <= n; a++) {
        if (dist[a] != INF && dist[a] <= m) {
            sum += node[a];
        }
    }
    Max = max(Max, sum);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> r;
    graph.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        cin >> t;
        node[i] = t;
    }

    int a, b, c;
    for (int j = 0; j < r; j++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        ds(k);
    }

    cout << Max;
    return 0;
}
