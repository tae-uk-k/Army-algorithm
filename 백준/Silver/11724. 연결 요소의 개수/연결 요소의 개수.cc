#include <bits/stdc++.h>
using namespace std;

int sum=0;

void bfs(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sum++;

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

    for (int u : graph[start]) {
        if (!visited[u]) {
            dfs(graph, u, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> graph(N + 1);
    
    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    vector<bool> visited(N + 1, false);
    for (int i=1; i<=N; i++) {
        if(visited[i]==false){
            dfs(graph, i, visited);
            sum++;
        }
    }
    cout<<sum;
    
    return 0;
}