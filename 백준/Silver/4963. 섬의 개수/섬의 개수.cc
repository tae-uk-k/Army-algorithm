#include <bits/stdc++.h>
using namespace std;

int x_dir[8] = {-1, 1, 0, 0, 1, -1, -1, 1}; 
int y_dir[8] = {0, 0, -1, 1, 1, 1, -1, -1}; 
int N, M;

void bfs(vector<vector<int>>& map, int a, int b) {
    queue<pair<int, int>> land;
    land.push({a,b});
    map[a][b]=-1;
    
    while (!land.empty()) {
        auto [x, y] = land.front();
        land.pop();

        for (int i = 0; i < 8; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= M && map[x_new][y_new] == 1) {
                map[x_new][y_new] = -1;
                land.push({x_new, y_new});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    while(true){
        int sum=0;
        cin >> M >> N;
        if(N==0&&M==0)return 0;

        vector<vector<int>> map(N + 1, vector<int>(M + 1, -1));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> map[i][j];
            }
        }
    
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if(map[i][j]==1){
                    bfs(map, i, j);
                    sum++;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}