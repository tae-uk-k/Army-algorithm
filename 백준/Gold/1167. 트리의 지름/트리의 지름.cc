#include <bits/stdc++.h>
using namespace std;
int N;
int ans=0;
int Max=0;

void bfs(vector<vector<pair<int, int>>>tree, int start){
    vector<int>visited(N+1, -1);
    visited[start]=0;
    queue<int>q;
    q.push(start);
    
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(pair<int, int>nood : tree[now]){
            if(visited[nood.first]!=-1)continue;
            int next=nood.first;
            int weight=nood.second;
            visited[next]=visited[now]+weight;
            if(visited[next]>Max){
                Max=visited[next];
                ans=next;
            }
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    vector<vector<pair<int, int>>> tree(N + 1);
    
    for(int i=0; i<N; i++){
        int nood, next, dist;
        cin>>nood;
        while(cin>>next && next!=-1){
            cin>>dist;
            tree[nood].push_back({next, dist});
            tree[next].push_back({nood, dist});
        }
    }
    bfs(tree, 1);
    bfs(tree, ans);
    cout<<Max;

    return 0;
}











