#include <bits/stdc++.h>
using namespace std;

int N, M;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1}; 

void bfs( vector<vector<bool>>flooded, vector<vector<bool>>& visited, int a, int b){
    queue<pair<int , int>>q;
    q.push({a,b});
    visited[a][b]=1;
    
    while(!q.empty()){
        auto [x, y]=q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= M && visited[x_new][y_new] == 0&&flooded[x_new][y_new]==0){
                q.push({x_new,y_new});
                visited[x_new][y_new]=1;
            }
        }
    }
}

int main() {
    cin>>N;
    M=N;
    
    int maxSum=0;
    int max=0;
    
    vector<vector<int>>area(N+1, vector<int>(N+1, 0));
    vector<vector<bool>>flooded(N+1, vector<bool>(N+1, 0));
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>area[i][j];
            if(area[i][j]>max)max=area[i][j];
        }
    }
    
    for(int k=-1; k<=max; k++){
        int sum=0;
        vector<vector<bool>>visited(N+1, vector<bool>(N+1, 0));
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(area[i][j]<=k)flooded[i][j]=1;
            }
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(flooded[i][j]==0&&visited[i][j]==0){bfs(flooded, visited, i, j);
                sum++;}
            }
        }
        
        maxSum=(sum>maxSum) ? sum : maxSum;
    }
    
    cout<<maxSum;
    return 0;
}