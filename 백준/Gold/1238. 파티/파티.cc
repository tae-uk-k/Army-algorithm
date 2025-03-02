#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
vector<int> dijkstra(int source, const vector<vector<pair<int,int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while(!pq.empty()){
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        
        if(cur_dist > dist[cur]) continue;
        
        for(auto &edge : graph[cur]){
            int next = edge.first;
            int cost = edge.second;
            if(dist[next] > cur_dist + cost){
                dist[next] = cur_dist + cost;
                pq.push({dist[next], next});
            }
        }
    }
    
    return dist;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, X;
    cin >> N >> M >> X;
    
    vector<vector<pair<int,int>>> graph(N+1), graph_rev(N+1);
    
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph_rev[b].push_back({a, c});
    }
    
    vector<int> dist_from = dijkstra(X, graph);
    
    vector<int> dist_to = dijkstra(X, graph_rev);
    
    int answer = 0;
    for(int i = 1; i <= N; i++){
        if(dist_from[i] < INF && dist_to[i] < INF){
            answer = max(answer, dist_from[i] + dist_to[i]);
        }
    }
    
    cout << answer;
    
    return 0;
}
