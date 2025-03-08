#include <bits/stdc++.h>
using namespace std;

vector<int> s;

void bfs(vector<vector<int>> &space, vector<vector<bool>> &visited,int a,int b) {
    int sum=1;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x + 1 <= space.size() - 1 && space[x + 1][y] == 1 && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            sum++;
            q.push({x + 1, y});
        }
        if (x - 1 >= 1 && space[x - 1][y] == 1 && !visited[x - 1][y]) {
            visited[x - 1][y] = true;
            sum++;
            q.push({x - 1, y});
        }
        if (y + 1 <= space[0].size() - 1 && space[x][y + 1] == 1 && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            sum++;
            q.push({x, y + 1});
        }
        if (y - 1 >= 1 && space[x][y - 1] == 1 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            sum++;
            q.push({x, y - 1});
        }
    }
    s.push_back(sum);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> space(N + 1, vector<int>(M + 1, 0));
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin>>space[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        for (int j = 1; j <= M; j++){
            if(visited[i][j]!=true&&space[i][j]==1){
                bfs(space, visited,i,j);
            }
        }
    }
    sort(s.begin(),s.end());
    cout<<s.size()<<"\n";
    if(s.size()==0)cout<<0;
    else cout<<s[s.size()-1];
    return 0;
}