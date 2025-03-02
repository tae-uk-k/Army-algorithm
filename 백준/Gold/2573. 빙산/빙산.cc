#include <bits/stdc++.h>
using namespace std;

int N, M;
int year = 0;
int iceberg_sum = 0;
int x_dir[4] = {-1, 1, 0, 0}; 
int y_dir[4] = {0, 0, -1, 1}; 

void Next_year(vector<vector<int>>& iceberg) { // 숫자 하나하나 돌면서 접한 물의 면 만큼 크기를 줄여야 하지만 원본에서 면의 양을 구하고 카피에 적용할 것 그 다음 원본에 붙여넣기.
    vector<vector<int>> copy = iceberg;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) { // iceberg를 순회
            if (iceberg[i][j] != 0) { // 빙산을 발견하면
                int side_sum = 0;
                for (int k = 0; k < 4; k++) { // 빙산의 동서남북 중에 물과 닿아있는 면의 수 세기
                    int next_x = i + x_dir[k];
                    int next_y = j + y_dir[k];
                    if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= M && iceberg[next_x][next_y] == 0) {
                        side_sum++;
                    }
                }
                copy[i][j] = max(0, copy[i][j] - side_sum); // 음수가 되지 않도록 보정
            }
        }
    }
    iceberg = copy; // 빙산 벡터에 적용
}

void iceberg_num(vector<vector<int>>& iceberg) { // 빙산의 개수 세기
    iceberg_sum = 0;
    vector<vector<int>> visited = iceberg; // 복사해놨다가 방문하면 0으로 바꾸기.
    queue<pair<int, int>> q;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (visited[i][j] != 0) {
                q.push({i, j});
                visited[i][j] = 0;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int next_x = x + x_dir[k]; // 수정: x -> x (i가 아니라 x)
                        int next_y = y + y_dir[k]; // 수정: y -> y (j가 아니라 y)
                        if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= M && visited[next_x][next_y] != 0) {
                            q.push({next_x, next_y});
                            visited[next_x][next_y] = 0;
                        }
                    }
                }
                iceberg_sum++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<vector<int>> iceberg(N + 1, vector<int>(M + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> iceberg[i][j];
        }
    }
    
    while (true) { // 빙산이 끝까지 나누어지지 않고 끝나면 0을 출력해야 하지만 일단 나중에 구현할거야 건들지 마
        iceberg_num(iceberg); // 빙산 개수 갱신 추가
        if (iceberg_sum >= 2) break;
        if (iceberg_sum == 0) { // 모든 빙산이 녹으면 0 출력
            cout << 0;
            return 0;
        }
        year++;
        Next_year(iceberg);
    }
    cout << year;
    
    return 0;
}
