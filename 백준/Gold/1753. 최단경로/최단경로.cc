#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int V, E, start;
    cin>> V >> E >> start;
    vector<vector<pair<int, int>>> graph(V + 1);//pair.first:도착노드, pair.second:가중치
    vector<int> dist(V + 1, INF);
    
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight] : graph[now]) {
            int nextCost = cost + weight;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
