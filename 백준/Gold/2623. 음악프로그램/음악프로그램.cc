#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int past, now, singer_num;
        past=0;
        cin>>singer_num;
        for(int j=0; j<singer_num; j++){
            cin>>now;
            if(past!=0){
                E[past].push_back(now);
                indegree[now]++;
            }
            past=now;
        }
    }

    queue<int>q;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    if(q.empty()){cout<<0;return 0;}
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : E[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if(ans.size()!=N){cout<<0; return 0;}
    for (int x : ans) {
        cout << x << "\n";
    }
    return 0;
}
