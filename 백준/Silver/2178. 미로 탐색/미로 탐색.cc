#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &space, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    space[1][1] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x + 1 <= space.size() - 1 && space[x + 1][y] == 1 && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            space[x + 1][y] = space[x][y] + 1;
            q.push({x + 1, y});
        }
        if (x - 1 >= 1 && space[x - 1][y] == 1 && !visited[x - 1][y]) {
            visited[x - 1][y] = true;
            space[x - 1][y] = space[x][y] + 1;
            q.push({x - 1, y});
        }
        if (y + 1 <= space[0].size() - 1 && space[x][y + 1] == 1 && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            space[x][y + 1] = space[x][y] + 1;
            q.push({x, y + 1});
        }
        if (y - 1 >= 1 && space[x][y - 1] == 1 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            space[x][y - 1] = space[x][y] + 1;
            q.push({x, y - 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> space(N + 1, vector<int>(M + 1, 0));
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

    for (int i = 1; i <= N; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= M; j++) {
            space[i][j] = row[j - 1] - '0';
        }
    }

    bfs(space, visited);
    cout << space[N][M];
    return 0;
}
