#include <bits/stdc++.h>
using namespace std;

/*필요한거:
    우선 사과랑 뱀의 위치를 나타낼 2차원 벡터가 필요하다.
    뱀이 위치하고있는 모든 좌표를 담고있는 큐가 필요하다. 
    머리의 좌표를 넣고, 머리가 사과의 위치랑 겹치지 않으면 꼬리를 pop 한다. 
    뱀의 머리를 옮기기 전에 그 위치에 사과가 있는지 판단하거나,
    뱀의 위치를 나타내는 벡터와 사과 위치 벡터를 분리 해야 한다.
    각 방향별 머리 좌표에 더해줄 숫자를 저장해뒀다가 방향이 오른쪽이면 다음 숫자, 왼쪽이면 이전 숫자를 더하는 방식으로 한다.
    방향 전환은 hash map이나 큐에 넣어놓자.
    게임이 끝나는지 판단해서 게임을 끝내는 함수도 만들자.  
*/

int x_dir[4] = {0, 1, 0, -1};
int y_dir[4] = {1, 0, -1, 0};
int snake_dir = 0; // 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위
int x = 1;
int y = 1;
int next_x, next_y;
pair<int, int> snake_head = {1,1};
int play_time = 0;

int main() {
    int N, K, ax, ay, L;
    queue<pair<int,int>> cmd;
    queue<pair<int, int>> snake;
    int comand_time;
    int comand_toint;
    char comand;
    
    cin >> N >> K;
    vector<vector<int>> space(N + 1, vector<int>(N + 1, -1)); // -1: 빈 공간, 0: 뱀, 1: 사과
    space[1][1] = 0;
    // 초기 뱀의 위치를 큐에 넣음
    snake.push({1,1});
    
    for (int i = 0; i < K; i++){
        cin >> ax >> ay;
        space[ax][ay] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++){
        cin >> comand_time >> comand;
        if (comand == 'L') comand_toint = -1; // 왼쪽은 -1
        if (comand == 'D') comand_toint = 1;  // 오른쪽은 +1
        cmd.push({comand_time, comand_toint});
    }
    // 여기까지 입력 받아서 정리 완료.
    /*
    뱀의 머리가 이동할 좌표를 구하고, 그 위치에 사과가 있는지, 벽이나 몸이 있는지 확인.
    사과가 없으면 꼬리를 pop하고, 사과가 있으면 꼬리는 그대로 둔다.
    머리 이동 전에 충돌 여부를 먼저 검사한다.
    */
    
    while (1) {
        play_time++;
        next_x = x + x_dir[snake_dir];
        next_y = y + y_dir[snake_dir];
        
        // 벽에 부딪히거나, 뱀의 몸(0)이 있는 경우 게임 종료
        if (next_x < 1 || next_x > N || next_y < 1 || next_y > N || space[next_x][next_y] == 0) {
            cout << play_time;
            return 0;
        }
        
        // 사과가 없으면 꼬리를 자른다.
        if (space[next_x][next_y] != 1) {
            auto [tx, ty] = snake.front();
            snake.pop();
            space[tx][ty] = -1;
        }
        // 이동한 곳에 사과가 있으면 사과는 없어지고 뱀은 길어짐.
        space[next_x][next_y] = 0;
        snake.push({next_x, next_y});
        
        // 머리 좌표 업데이트
        x = next_x;
        y = next_y;
        
        if (!cmd.empty() && play_time == cmd.front().first) {
            snake_dir += cmd.front().second;
            if (snake_dir == -1) snake_dir = 3;
            if (snake_dir == 4) snake_dir = 0;
            cmd.pop();
        }
    }
    
    return 0;
}
