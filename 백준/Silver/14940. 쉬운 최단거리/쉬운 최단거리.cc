#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};
int N,M;

void bfs(vector<vector<int>>& information, vector<vector<int>>& dist, queue<pair<int, int>>& q){
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            if(x_new >= 0 && x_new < N && y_new >= 0 && y_new < M && information[x_new][y_new] == 1 && dist[x_new][y_new]==-1){
                dist[x_new][y_new]=dist[x][y]+1;
                q.push({x_new, y_new});
            }
        }
    }
}

int main() {
    cin>>N>>M;
    
    vector<vector<int>>information(N,vector<int>(M,0));
    vector<vector<int>>dist(N,vector<int>(M,-1));
    queue<pair<int, int>>q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>information[i][j];
            if(information[i][j]==2){
                q.push({i,j});
                dist[i][j]=0;
            }
            if(information[i][j]==0)dist[i][j]=0;
        }
    }
    
    bfs(information, dist, q);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}