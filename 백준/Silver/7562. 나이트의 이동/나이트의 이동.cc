#include <bits/stdc++.h>
using namespace std;

int x_dir[8] = {2, 2, -2, -2, 1, -1, 1, -1}; 
int y_dir[8] = {1, -1, 1, -1, 2, 2, -2, -2};
int N,T,sx,sy,gx,gy;

void bfs(vector<vector<int>>& dist){

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy]=0;
    
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 8; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if(x_new >= 0 && x_new <= T-1 && y_new >= 0 && y_new <= T-1 && dist[x_new][y_new] == -1 ) {
                q.push({x_new, y_new});
                dist[x_new][y_new] = dist[x][y]+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>T;
        vector<vector<int>>dist(T+1,vector<int>(T+1,-1));
        cin>>sx>>sy>>gx>>gy;
        bfs(dist);
        cout<<dist[gx][gy]<<"\n";
    }
    
    return 0;
}
















