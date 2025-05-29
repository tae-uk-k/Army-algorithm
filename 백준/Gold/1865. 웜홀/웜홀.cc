#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;

struct Edge {
    int from, to;
    long long cost; 
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int R=0; R<TC; R++){
        int V, M, W;
        cin >> V >> M >> W;

        vector<Edge> edges;
        edges.reserve(M * 2 + W);
        
        for (int i = 0; i < M; i++) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            edges.push_back({a, b, c});
            edges.push_back({b, a, c});
        }
        for (int i = 0; i < W; i++) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            edges.push_back({a, b, -c});
        }
    
        vector<long long> dist(V + 1, 0);

        for (int i = 1; i <= V - 1; i++) {
            for (const auto& e : edges) {
                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }

        bool negativeCycle = false;
        for (const auto& e : edges) {
            if (dist[e.to] > dist[e.from] + e.cost) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle){
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
}
