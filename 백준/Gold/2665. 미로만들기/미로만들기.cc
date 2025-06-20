#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};

int main() {
    int N;
    cin>>N;
    vector<string>map(N);//string썼으니까 0base로 가자 int가 아니라 chr로 접근하는거 잊지말자 
    vector<vector<int>>dist(N, vector<int>(N, INF));
    
    for(int i=0; i<N; i++){
        cin>>map[i];
    }
    
    priority_queue< tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
    pq.push({0,0,0});//cost,x,y
    dist[0][0]=0;
    
    while(!pq.empty()){
        auto[cost,nowX,nowY]=pq.top();
        pq.pop();
        
        if(cost>dist[nowX][nowY])continue;
        
        for(int j=0; j<4; j++){
            int nextX=nowX+x_dir[j];
            int nextY=nowY+y_dir[j];
            if(nextX<0||nextY<0||nextX>=N||nextY>=N)continue;
            int nextCost=(map[nextX][nextY]=='0') ? (cost+1):(cost);
            if(dist[nextX][nextY]>nextCost){
                dist[nextX][nextY]=nextCost;
                pq.push({nextCost,nextX,nextY});
            }
            
        }
    }
    cout<<dist[N-1][N-1];
    
    return 0;
}