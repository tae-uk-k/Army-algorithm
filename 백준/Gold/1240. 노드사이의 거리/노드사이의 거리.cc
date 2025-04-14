#include <bits/stdc++.h>
using namespace std;
int N,M;

int bfs(vector<vector<int>>& tree, int start, int end){
    vector<int>visited(N+1, -1);//거리도 같이 저장하자 
    visited[start]=0;
    int now=start;
    queue<int>q;
    while(visited[end]==-1){
        for(int i=1; i<N+1; i++){
            if(tree[now][i]!=0&&visited[i]==-1){
                q.push(i);
                visited[i]=visited[now]+tree[now][i];
            }
        }
        now=q.front();
        q.pop();
    }
    return visited[end];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>M;
    vector<vector<int>>tree(N+1, vector<int>(N+1, 0));
    for(int i=0; i<N-1; i++){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a][b]=c;
        tree[b][a]=c;
    }
    
    for(int j=0; j<M; j++){
        int d,e;
        cin>>d>>e;
        cout<<bfs(tree,d,e)<<"\n";
    }
    
    return 0;
}