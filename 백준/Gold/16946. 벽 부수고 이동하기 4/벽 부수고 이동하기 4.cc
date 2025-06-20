#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};
int N, M;


void bfs(int a, int b,
         vector<vector<int>>& mp,
         vector<vector<int>>& regionId,
         vector<int>& regionSize,
         int curId)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    regionId[a][b] = curId;
    int sum = 1;
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            int X = x + x_dir[d];
            int Y = y + y_dir[d];
            if (X>0 && X<=N && Y>0 && Y<=M
                && mp[X][Y]==0
                && regionId[X][Y]==0)
            {
                regionId[X][Y] = curId;
                sum++;
                q.push({X,Y});
            }
        }
    }
    regionSize[curId] = sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> mp(N+1, vector<int>(M+1, -1));
    vector<vector<int>> ans(N+1, vector<int>(M+1, 1));//여기에는 정답을 저장하자 
    queue<pair<int,int>> wall;


    for(int i=1; i<=N; i++){
        string s; cin >> s;
        for(int j=1; j<=M; j++){
            mp[i][j] = s[j-1] - '0';
            if (mp[i][j]==1) wall.push({i,j});
            else ans[i][j] = 0;
        }
    }


    vector<vector<int>> regionId(N+1, vector<int>(M+1, 0));
    vector<int> regionSize(1, 0);


    int curId = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if (mp[i][j]==0 && regionId[i][j]==0) {
                curId++;
                regionSize.push_back(0);
                bfs(i, j, mp, regionId, regionSize, curId);
            }
        }
    }


    while(!wall.empty()){
        auto [a,b] = wall.front(); wall.pop();
        unordered_set<int> seen;
        int total = 0;
        for(int d=0; d<4; d++){
            int X = a + x_dir[d], Y = b + y_dir[d];
            if (X>0 && X<=N && Y>0 && Y<=M) {
                int rid = regionId[X][Y];
                if (rid>0 && !seen.count(rid)) {
                    seen.insert(rid);
                    total += regionSize[rid];
                }
            }
        }
        ans[a][b] = (ans[a][b] + total) % 10;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}
