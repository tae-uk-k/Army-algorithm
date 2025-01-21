#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_shortest_path(int n, vector<vector<int>>& adj, int start) {
    vector<int> dist(n+1, INT_MAX); 
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) {  
                dist[neighbor] = dist[node] + 1;  
                q.push(neighbor);
            }
        }
    }
    
    return dist;
}

int main() {
    int N,M,start,end;
    cin>>N>>start>>end>>M;
    
    int a,b;
    vector<vector<int>>Ki(N+1);
    
    for(int i=0; i<M; i++){
        cin>>a>>b;
        Ki[a].push_back(b);
        Ki[b].push_back(a);
    }
    
    for (int i = 1; i <= N; ++i) {
        sort(Ki[i].begin(), Ki[i].end());
    }
    
    vector<int> shortest_distances = bfs_shortest_path(N, Ki, start);
    if(shortest_distances[end]==INT_MAX){
        cout<<-1;
        return 0;
    }
    cout<<shortest_distances[end];
    return 0;
}