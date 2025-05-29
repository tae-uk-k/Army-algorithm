#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;

struct Edge {
    int from, to;
    long long cost; 
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V, E;
    int start=1;
    cin >> V >> E;
    
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    
    vector<long long> dist(V + 1, INF);
    dist[start] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }

    bool negativeCycle = false;
    for (const auto& e : edges) {
        if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle){
        cout<<-1;
        return 0;
    }
    else {
        for (int i = 2; i <= V; i++) {
            if (dist[i] == INF) cout <<-1<<"\n";
            else cout << dist[i] << '\n';
        }
    }
    
    return 0;
}
