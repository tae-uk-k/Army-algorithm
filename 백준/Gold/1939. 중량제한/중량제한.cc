#include <bits/stdc++.h>
using namespace std;
const int INF=1000000001;

int main() {
    int N,M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>>Edge(N+1);
    vector<int>limit(N+1,-1);
    priority_queue<pair<int,int>>pq;
    
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edge[a].push_back({b,c});
        Edge[b].push_back({a,c});
    }
    
    int start, end;
    cin>>start>>end;
    
    limit[start]=INF;
    pq.push({INF, start});
    
    while(!pq.empty()){
        auto[LIMIT, now]=pq.top();
        pq.pop();
        
        if(LIMIT<limit[now])continue;
        
        for(auto[next, weight]:Edge[now]){
            int nextlimit=min(LIMIT, weight);
            if(nextlimit>limit[next]){
                limit[next]=nextlimit;
                pq.push({nextlimit, next});
            }
        }
    }
    
    cout<<limit[end];
    return 0;
}










