#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> Edge(N+1);
    vector<vector<int>> Chart(N+1, vector<int>(N+1, INF));
    int a, b, c;
    for(int i = 1; i <= M; i++){
        cin >> a >> b >> c;
        Edge[a].push_back({b, c});
        Edge[b].push_back({a, c});
    }

    for(int j = 1; j <= N; j++){
        vector<int> dist(N+1, INF);
        vector<int> past(N+1, INF);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        dist[j] = 0;
        pq.push({0, j});

        while(!pq.empty()){
            auto [cost, now] = pq.top(); 
            pq.pop();
            if(dist[now] < cost) continue;
            for(auto [nx, w] : Edge[now]){
                int nc = cost + w;
                if(nc < dist[nx]){
                    dist[nx] = nc;
                    pq.push({nc, nx});
                    past[nx] = now;
                }
            }
        }

        for(int k = 1; k <= N; k++){
            if(k == j){
                Chart[j][k] = -1;
            } else {
                int cur = k;
                while(past[cur] != j) 
                    cur = past[cur];
                Chart[j][k] = cur;
            }
        }
    }

    for(int p = 1; p <= N; p++){
        for(int q = 1; q <= N; q++){
            if(Chart[p][q] == -1) 
                cout << "- ";
            else 
                cout << Chart[p][q] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
