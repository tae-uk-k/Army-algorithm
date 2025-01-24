#include <bits/stdc++.h>
using namespace std;

int maxSafeArea=0;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};
int N,M;


void bfs(queue<pair<int, int>> virus, vector<vector<int>> area) {
    int S=0;
    while (!virus.empty()) {
        auto [x, y] = virus.front();
        virus.pop();
        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= M && area[x_new][y_new] == 0) {
                virus.push({x_new, y_new});
                area[x_new][y_new] = 2;
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(area[i][j]==0){
                S++;
            }
        }
    }
    if(S>maxSafeArea)maxSafeArea=S;
}

int main() {
    cin >> N >> M;

    vector<vector<int>> area(N + 1, vector<int>(M + 1, -1));
    queue<pair<int, int>> virus;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>area[i][j];
            if(area[i][j]==2){
                virus.push({i,j});
            }
        }
    }

    for (int i1 = 1; i1 <=N; ++i1) {
        for (int i2 = 1; i2 <=M; ++i2) {
            if(area[i1][i2]==0){
                area[i1][i2]=1;
            }
            else{
                continue;
            }
            for (int i3 = 1; i3 <=N; ++i3) {
                for (int i4 = 1; i4 <=M; ++i4) {
                    if(area[i3][i4]==0){
                        area[i3][i4]=1;
                    }
                    else{
                        continue;
                    }
                    for (int i5 = 1; i5 <=N; ++i5) {
                        for (int i6 = 1; i6 <=M; ++i6) {
                            if(area[i5][i6]==0){
                                area[i5][i6]=1;
                                bfs(virus, area);
                                area[i5][i6] = 0;
                            }
                        }
                    }
                    area[i3][i4] = 0;
                }
            }
            area[i1][i2] = 0;
        }
    }
    cout<<maxSafeArea;

    return 0;
}