#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1};
int RGB_sum = 0;
int RRB_sum = 0;
int N;

void RGB_bfs(vector<vector<char>>& RGB, vector<vector<bool>>& RGB_visited, int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    RGB_visited[a][b] = 1;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= N && RGB_visited[x_new][y_new] == 0 && RGB[x_new][y_new] == RGB[x][y]) {
                q.push({x_new, y_new});
                RGB_visited[x_new][y_new] = 1;
            }
        }
    }
    RGB_sum++;
}

void RRB_bfs(vector<vector<char>>& RRB, vector<vector<bool>>& RRB_visited, int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    RRB_visited[a][b] = 1;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            
            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= N && RRB_visited[x_new][y_new] == 0 && RRB[x_new][y_new] == RRB[x][y]) {
                q.push({x_new, y_new});
                RRB_visited[x_new][y_new] = 1;
            }
        }
    }
    RRB_sum++;
}

int main() {
    cin >> N;
    
    vector<vector<char>> RGB(N + 1, vector<char>(N + 1, 0));
    vector<vector<char>> RRB(N + 1, vector<char>(N + 1, 0));
    vector<vector<bool>> RGB_visited(N + 1, vector<bool>(N + 1, 0));
    vector<vector<bool>> RRB_visited(N + 1, vector<bool>(N + 1, 0));
    string s;
    
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= N; j++) {
            RGB[i][j] = s[j - 1];
            if (s[j - 1] == 'G') {
                RRB[i][j] = 'R';
            } else {
                RRB[i][j] = s[j - 1];
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (RGB_visited[i][j] == 0) {
                RGB_bfs(RGB, RGB_visited, i, j);
            }
            if (RRB_visited[i][j] == 0) {
                RRB_bfs(RRB, RRB_visited, i, j);
            }
        }
    }
    
    cout << RGB_sum << ' ' << RRB_sum;
    
    return 0;
}
