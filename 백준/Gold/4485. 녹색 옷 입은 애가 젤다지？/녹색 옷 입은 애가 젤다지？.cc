#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    queue<int> ans;
    while(true){
        int N;
        cin>>N;
        if(N==0)break;
        
        vector<vector<int>>map(N, vector<int>(N, INF));
        vector<vector<int>>dist(N, vector<int>(N, INF));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
            }
        }
        
        priority_queue< tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
        pq.push({map[0][0],0,0});//cost,x,y
        dist[0][0]=map[0][0];
        
        while(!pq.empty()){
            auto[cost,nowX,nowY]=pq.top();
            pq.pop();
        
            if(cost>dist[nowX][nowY])continue;
        
            for(int j=0; j<4; j++){
                int nextX=nowX+x_dir[j];
                int nextY=nowY+y_dir[j];
                if(nextX<0||nextY<0||nextX>=N||nextY>=N)continue;
                int nextCost=cost+map[nextX][nextY];
                if(dist[nextX][nextY]>nextCost){
                    dist[nextX][nextY]=nextCost;
                    pq.push({nextCost,nextX,nextY});
                }
            
            }
        }
        ans.push(dist[N-1][N-1]);
    }
    for(int a=1; !ans.empty(); a++){
        cout<<"Problem "<<a<<": "<<ans.front()<<"\n";
        ans.pop();
    }
    return 0;
}
