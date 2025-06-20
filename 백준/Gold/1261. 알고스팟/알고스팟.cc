#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int x_dir[4] = {-1, 1, 0, 0}; 
    int y_dir[4] = {0, 0, -1, 1};
    int N,M;
    cin >> M >> N; 
    vector<vector<int>>maze(N+1, vector<int>(M+1));
    vector<vector<int>>dist(N+1, vector<int>(M+1, INF));
    dist[1][1]=0;

    vector<string> raw(N);
    for(int i = 0; i < N; i++){
        cin >> raw[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
         maze[i][j] = raw[i-1][j-1] - '0';
        }
    }
    priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>> > pq;
    pq.push({0,1,1});//도착지점이 1,1이면서 1,1까지 비용이 0인 간선추가.
    
    while(!pq.empty()){
        auto [cost, x, y] = pq.top();
        pq.pop();

        if (dist[x][y] < cost) continue;
        
        for(int k=0; k<4; k++){
            int next_x= x+x_dir[k];
            int next_y= y+y_dir[k];
            //만약 범위를 벗어나면 continue하고
            if(next_x<=0||next_x>N||next_y<=0||next_y>M)continue;
            int next_cost=cost+maze[next_x][next_y];
            if(next_cost<dist[next_x][next_y]){
                dist[next_x][next_y]=next_cost;
                pq.push({next_cost,next_x,next_y});
            }
        }
    }
    cout<<dist[N][M];
    return 0;
}
