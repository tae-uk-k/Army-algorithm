#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(
    vector<string>& map,
    vector<vector<bool>>& visited,
    int h, int w,
    int& docSum,
    unordered_map<char, vector<pair<int,int>>>& doors, 
    queue<pair<int, int>>& bfsCrd, unordered_set<char>& keys
){

    while(!bfsCrd.empty()){
        auto [X,Y] = bfsCrd.front();
        bfsCrd.pop();
        
        for(int l=0; l<4; l++){
            int nx = X + dx[l];
            int ny = Y + dy[l];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny]) continue;
            char c = map[nx][ny];

            if (c == '*') continue;

            // 빈 칸
            if (c == '.') {
                visited[nx][ny] = true;
                bfsCrd.push({nx, ny});
                continue;
            }

            // 문
            if (c >= 'A' && c <= 'Z') {
                char keyChar = c - 'A' + 'a';
                if (keys.count(keyChar)) {
                    map[nx][ny] = '.';
                    visited[nx][ny] = true;
                    bfsCrd.push({nx, ny});
                } else {
                    doors[c].push_back({nx, ny});
                }
                continue;
            }

            // 키
            if (c >= 'a' && c <= 'z') {
                visited[nx][ny] = true;
                bfsCrd.push({nx, ny});
                if (!keys.count(c)) {
                    keys.insert(c);
                    char doorChar = c - 'a' + 'A';
                    if (doors.count(doorChar)) {
                        for (auto &pos : doors[doorChar]) {
                            if (!visited[pos.first][pos.second]) {
                                visited[pos.first][pos.second] = true;
                                bfsCrd.push(pos);
                            }
                        }
                        doors.erase(doorChar);
                    }
                }
                continue;
            }

            // 문서
            if (c == '$') {
                docSum++;
                visited[nx][ny] = true;
                bfsCrd.push({nx, ny});
                continue;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int h, w;
        cin >> h >> w;
        string k;
        int docSum = 0;

        vector<string> map(h);
        for (int i = 0; i < h; i++) {
            cin >> map[i];
        }
        
        cin >> k;
        unordered_set<char> keys;
        if (k[0] != '0') {
            for (char c: k) keys.insert(c);
        }

        queue<pair<int, int>> bfsCrd;
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        unordered_map<char, vector<pair<int,int>>> doors;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == '*') {
                    visited[i][j] = true;
                }
                if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {//건물 진입경로 파악 bfs가 아니니까 
                    //------키 만났을 때 ----------------------------------------------
                    // bfs하면서 상하좌우 탐색중이 아니니까 키 추가만 하고 끝내자.
                    if (map[i][j] >= 'a' && map[i][j] <= 'z') {
                        if (!keys.count(map[i][j])) {
                            keys.insert(map[i][j]);//없는 키면 추가 
                        }
                        visited[i][j] = true;
                        bfsCrd.push({i, j});
                        continue;
                    }
                    //------문 만났을 때 ----------------------------------------------
                    //문목록에 넣고 
                    if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
                        doors[map[i][j]].push_back({i, j});
                    }
                    //------문서 만났을 때 ----------------------------------------------
                    if (map[i][j] == '$') {
                        docSum++;
                        visited[i][j] = true;
                        bfsCrd.push({i, j});
                        continue;
                    }
                    if (map[i][j] == '.') {
                        bfsCrd.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }
        //bfs하기 전에 문 목록에서 열리는게 뭐뭐있는지 파악해야한다. bfs로 못 만나는 문이 있을 수 있음.
        for (char c : keys) {
            char doorChar = c - 'a' + 'A';
            if (doors.count(doorChar)) {
                for (auto &pos : doors[doorChar]) {
                    if (!visited[pos.first][pos.second]) {
                        visited[pos.first][pos.second] = true;
                        bfsCrd.push(pos);
                    }
                }
                doors.erase(doorChar);
            }
        }
        bfs(map, visited, h, w, docSum, doors, bfsCrd, keys);
        cout << docSum << "\n";
    }

    return 0;
}