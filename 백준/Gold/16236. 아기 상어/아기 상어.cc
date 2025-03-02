#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> space;
int N;
int survival_time = 0;
int eat_fish_num = 0;
int shark_size = 2;
pair<int, int> loc_fish = {-1, -1};//fish에서 찾으면 좌표를 여기에 저장.
pair<int, int> loc_shark;
const int INF = 987654321;
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

bool fish() {
    int min_dist_from_shark = INF;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));
    dist[loc_shark.first][loc_shark.second] = 0;
    queue<pair<int, int>> q;
    q.push({loc_shark.first, loc_shark.second});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if (x_new >= 1 && x_new <= N && y_new >= 1 && y_new <= N && space[x_new][y_new] <= shark_size && dist[x_new][y_new] == -1) {
                q.push({x_new, y_new});
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (space[i][j] != 0 && space[i][j] < shark_size && dist[i][j] != -1) { 
                if (dist[i][j] < min_dist_from_shark || (dist[i][j] == min_dist_from_shark && (i < loc_fish.first || (i == loc_fish.first && j < loc_fish.second)))) {
                    loc_fish = {i, j};
                    min_dist_from_shark = dist[i][j];
                }
            }
        }
    }

    if (min_dist_from_shark != INF) {
        survival_time += min_dist_from_shark;
        eat_fish_num++;
        space[loc_fish.first][loc_fish.second] = 0; 
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N;
    space.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                loc_shark = make_pair(i, j);
                space[i][j] = 0; // 상어의 위치는 따로 저장하고 나중에 지나갈 수 있게 0으로 만들어두자.
            }
        }
    }

    while (fish()) {
        loc_shark = loc_fish;
        if (eat_fish_num == shark_size) {
            shark_size++;
            eat_fish_num = 0; // 물고기 먹은 횟수 초기화
        }
    }
    cout << survival_time;
    return 0;
}
