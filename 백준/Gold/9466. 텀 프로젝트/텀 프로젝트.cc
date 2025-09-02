#include <bits/stdc++.h>
using namespace std;
int sum;

void dfs(vector<int>& indicate, vector<bool>& visited, int j, int N){
    vector<bool> vis(N, false);
    vector<int> path;
    int now = j;

    while(true){
        if(vis[now]) {
            int cycle_size = 0;
            bool in_cycle = false;
            for(int node : path){
                if(node == now) in_cycle = true;
                if(in_cycle){
                    cycle_size++;
                }
            }
            sum += cycle_size;
            break;
        }
        if(visited[now]) break;
        vis[now] = true;
        path.push_back(now);
        now = indicate[now];
    }

    for(int node : path){
        visited[node] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    for(int i=0; i<T; i++){
        sum=0;
        int N; cin>>N;
        vector<int>indicate(N);
        for(int k=0; k<N; k++){
            int choice; cin>>choice;
            indicate[k] = choice-1;
        }
        vector<bool>visited(N,false);
        for(int j=0; j<N; j++){
            if(!visited[j]){
                dfs(indicate, visited, j, N);
            }
        }
        cout<<N-sum<<"\n";
    }
    return 0;
}
