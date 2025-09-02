#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N,M; 
bool visited[50][50][64];

int bfs(vector<string>maze, int sx, int sy){
    queue<array<int,4>> q;
    q.push({sx, sy, 0, 0});
    visited[sx][sy][0] = true;

    while (!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur[0];
        int y = cur[1];
        int dist = cur[2];
        int keys = cur[3];
        
        if (maze[x][y] == '1') return dist;
        
        for(int l=0; l<4; l++){
            int nx= x+dx[l];
            int ny= y+dy[l];
            int newKeys = keys;
            
            if(nx<0||nx>=N||ny<0||ny>=M||maze[nx][ny] == '#')continue;
            
            if (maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') {
                int bit = maze[nx][ny] - 'a';
                newKeys |= (1 << bit);
            }
            if (maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F') {
                int bit = maze[nx][ny] - 'A';
                if (!(keys & (1 << bit))) {
                    continue;
                }
            }
            
            if (visited[nx][ny][newKeys]) continue;
            visited[nx][ny][newKeys] = true;
            q.push({nx, ny, dist + 1, newKeys});
        }
    }
    return -1;
}

int main() {
    cin>>N>>M;
    vector<string>maze(N);
    int sx,sy;
    
    for(int i=0; i<N; i++){
        cin>>maze[i];
    }
    for(int j=0; j<N; j++){
        for(int k=0; k<M; k++){
            if(maze[j][k]=='0'){
                sx=j;sy=k;
            }
        }
    }
    int ans=bfs(maze, sx, sy);
    cout << ans;
    return 0;
}