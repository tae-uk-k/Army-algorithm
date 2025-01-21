#include <bits/stdc++.h>
using namespace std;

int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1}; 

void bfs(queue<pair<int, int>>& q, vector<vector<int>>& tomato, vector<vector<int>>& dist, int N, int M) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= M && tomato[x_new][y_new] == 0) {
                tomato[x_new][y_new] = 1;
                q.push({x_new, y_new});

                if (dist[x_new][y_new] == -1 || dist[x_new][y_new] > dist[x][y] + 1) {
                    dist[x_new][y_new] = dist[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    cin >> M >> N;

    vector<vector<int>> tomato(N + 1, vector<int>(M + 1, -1));
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, -1));
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == -1) {
                dist[i][j] = -1;
            } else if (tomato[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    bfs(q, tomato, dist, N, M);

    int max_val = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (tomato[i][j] == 0 && dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            max_val = max(max_val, dist[i][j]);
        }
    }
    
    cout << max_val;
    return 0;
}
