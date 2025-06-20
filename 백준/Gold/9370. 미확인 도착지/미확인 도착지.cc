#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,t,s,g,h,a,b,d;

void Dijkstra(int start, int startcost, vector<int>& dist, vector<vector<pair<int,int>>>crossroads){
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({startcost,start});
    dist[start]=startcost;
    
    while(!pq.empty()){
        auto[cost, now]=pq.top();
        pq.pop();
        
        if(dist[now]<cost)continue;
        
        for(auto[weight, next]:crossroads[now]){
            int nextcost=cost+weight;
            if(dist[next]>nextcost){
                dist[next]=nextcost;
                pq.push({nextcost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    for(int test=0; test<T; test++){
        
        cin>>n>>m>>t>>s>>g>>h;
        vector<vector<pair<int,int>>>crossroads(n+1);
        vector<int>dist(n+1, INF);
        vector<int>distGtodest(n+1, INF);
        vector<int>distHtodest(n+1, INF);
        priority_queue<int, vector<int>, greater<int>> ans;
        int GHweight;
        
        for(int i=0; i<m; i++){
            cin>>a>>b>>d;
            crossroads[a].push_back({d,b});
            crossroads[b].push_back({d,a});
            if((a==g&&b==h)||(a==h&&b==g))GHweight=d;
        }
        
         Dijkstra(s,0,dist,crossroads);
         Dijkstra(g,dist[h]+GHweight,distGtodest,crossroads);
         Dijkstra(h,dist[g]+GHweight,distHtodest,crossroads);
         
         int destination;
         for(int j=0; j<t; j++){
             cin>>destination;
             if(dist[destination]==INF)continue;
             if(dist[destination]==distGtodest[destination]||dist[destination]==distHtodest[destination]){
                 ans.push(destination);
             }
         }
         
         while(!ans.empty()){
             cout<<ans.top()<<' ';
             ans.pop();
         }
         cout<<"\n";
    }
    return 0;
}









