#include <bits/stdc++.h>
using namespace std;

int visited[26]={0};
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1}; 
int N, M;
int ans=0;

void dfs(vector<string>& alp, int x, int y, int sum ){
    visited[alp[x][y]-'A']=1;
    if(sum>ans)ans=sum;
    for(int i=0; i<4; i++){
        int x_new = x+x_dir[i];
        int y_new = y+y_dir[i];
        if(x_new>=0 && y_new>=0 && x_new<N && y_new<M && visited[alp[x_new][y_new]-'A']==0){
            dfs(alp, x_new, y_new, sum+1);
        }
    }
    visited[alp[x][y]-'A']=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    vector<string> alp(N);
    
    for (int i = 0; i < N; i++) {
        cin >> alp[i];
    }
    
    dfs(alp, 0, 0, 1);
    
    cout<<ans;
    
    
    return 0;
}
