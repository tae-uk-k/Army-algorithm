#include <bits/stdc++.h>
using namespace std;

vector<int>sum;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};
int N,M,K;

void bfs(vector<vector<int>>& arr, int a, int b){
    int S=1;
    queue<pair<int, int>> q;
    q.push({a, b});
    arr[a][b]=1;
    
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if(x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= M && arr[x_new][y_new] == 0 ) {
                q.push({x_new, y_new});
                arr[x_new][y_new] = 1;
                S++;
            }
        }
    }
    sum.push_back(S);
}

int main() {
    cin>>N>>M>>K;
    
    vector<vector<int>>arr(N+1,vector<int>(M+1,0));
    int a;
    
    for(int i=0; i<K; i++){
        vector<int>A;
        for(int j=0; j<4; j++){
            cin>>a;
            A.push_back(a);
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(A[0]<j&&j<=A[2]&&A[1]<i&&i<=A[3]){
                    arr[i][j]= -1;
                }
            }
        }
        
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(arr[i][j]==0){
                bfs(arr,i,j);
            }
        }
    }
    
    sort(sum.begin(),sum.end());
    cout<<sum.size()<<"\n";
    for(int k : sum){
        cout<<k<<' ';
    }
    
    return 0;
}

















