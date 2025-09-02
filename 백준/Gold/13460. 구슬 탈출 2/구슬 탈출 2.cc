#include <bits/stdc++.h>
using namespace std;

int gx,gy,sRx,sRy,sBx,sBy;
int nRx,nRy,nBx,nBy;
queue<tuple<int,int,int,int>>q;

void up(vector<vector<vector<vector<int>>>>& visited, vector<string>& map){
    int Rx = get<0>(q.front());
    int Ry = get<1>(q.front());
    int Bx = get<2>(q.front());
    int By = get<3>(q.front());
    
    // 현재 위치에서 시작
    nRx=Rx;nRy=Ry;nBx=Bx;nBy=By;
    
    if(Rx<=Bx){
        // 빨간 구슬을 먼저 굴림
        while(nRx-1 >= 0 && map[nRx-1][nRy]!='#'){
            nRx--;
            if(nRx==gx&&nRy==gy) break;
        }
        
        // 파란 구슬 굴리기
        while(nBx-1 >= 0 && map[nBx-1][nBy]!='#'){
            nBx--;
            if(nBx==gx&&nBy==gy) return;
        }
        
        // 겹침 처리 (구멍이 아닐 때만)
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRx - Rx);
            int bdist = abs(nBx - Bx);
            if(rdist>bdist) nRx++;
            else nBx++;
        }
    }
    else{
        // 파란 구슬을 먼저 굴림
        while(nBx-1 >= 0 && map[nBx-1][nBy]!='#'){
            nBx--;
            if(nBx==gx&&nBy==gy) return;
        }
        
        while(nRx-1 >= 0 && map[nRx-1][nRy]!='#'){
            nRx--;
            if(nRx==gx&&nRy==gy) break;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRx - Rx);
            int bdist = abs(nBx - Bx);
            if(rdist>bdist) nRx++;
            else nBx++;
        }
    }
    
    // visited가 0이면 방문하지 않은 것 (-1로 초기화했으므로)
    if(visited[nRx][nRy][nBx][nBy]==-1){
        visited[nRx][nRy][nBx][nBy]=visited[Rx][Ry][Bx][By]+1;
        q.push({nRx,nRy,nBx,nBy});
        if(visited[nRx][nRy][nBx][nBy]<=10&&nRx==gx&&nRy==gy){
            cout<<visited[nRx][nRy][nBx][nBy];
            exit(0); 
        }
    }
}

void down(vector<vector<vector<vector<int>>>>& visited, vector<string>& map){
    int Rx = get<0>(q.front());
    int Ry = get<1>(q.front());
    int Bx = get<2>(q.front());
    int By = get<3>(q.front());
    
    nRx=Rx;nRy=Ry;nBx=Bx;nBy=By;
    
    if(Rx>=Bx){
        while(nRx+1 < visited.size() && map[nRx+1][nRy]!='#'){
            nRx++;
            if(nRx==gx&&nRy==gy) break;
        }
        
        while(nBx+1 < visited.size() && map[nBx+1][nBy]!='#'){
            nBx++;
            if(nBx==gx&&nBy==gy) return;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRx - Rx);
            int bdist = abs(nBx - Bx);
            if(rdist>bdist) nRx--;
            else nBx--;
        }
    }
    else{
        while(nBx+1 < visited.size() && map[nBx+1][nBy]!='#'){
            nBx++;
            if(nBx==gx&&nBy==gy) return;
        }
        
        while(nRx+1 < visited.size() && map[nRx+1][nRy]!='#'){
            nRx++;
            if(nRx==gx&&nRy==gy) break;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRx - Rx);
            int bdist = abs(nBx - Bx);
            if(rdist>bdist) nRx--;
            else nBx--;
        }
    }
    
    if(visited[nRx][nRy][nBx][nBy]==-1){
        visited[nRx][nRy][nBx][nBy]=visited[Rx][Ry][Bx][By]+1;
        q.push({nRx,nRy,nBx,nBy});
        if(visited[nRx][nRy][nBx][nBy]<=10&&nRx==gx&&nRy==gy){
            cout<<visited[nRx][nRy][nBx][nBy];
            exit(0); 
        }
    }
}

void left(vector<vector<vector<vector<int>>>>& visited, vector<string>& map){
    int Rx = get<0>(q.front());
    int Ry = get<1>(q.front());
    int Bx = get<2>(q.front());
    int By = get<3>(q.front());
    
    nRx=Rx;nRy=Ry;nBx=Bx;nBy=By;
    
    if(Ry<=By){
        while(nRy-1 >= 0 && map[nRx][nRy-1]!='#'){
            nRy--;
            if(nRx==gx&&nRy==gy) break;
        }
        
        while(nBy-1 >= 0 && map[nBx][nBy-1]!='#'){
            nBy--;
            if(nBx==gx&&nBy==gy) return;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRy - Ry);
            int bdist = abs(nBy - By);
            if(rdist>bdist) nRy++;
            else nBy++;
        }
    }
    else{
        while(nBy-1 >= 0 && map[nBx][nBy-1]!='#'){
            nBy--;
            if(nBx==gx&&nBy==gy) return;
        }
        
        while(nRy-1 >= 0 && map[nRx][nRy-1]!='#'){
            nRy--;
            if(nRx==gx&&nRy==gy) break;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRy - Ry);
            int bdist = abs(nBy - By);
            if(rdist>bdist) nRy++;
            else nBy++;
        }
    }
    
    if(visited[nRx][nRy][nBx][nBy]==-1){
        visited[nRx][nRy][nBx][nBy]=visited[Rx][Ry][Bx][By]+1;
        q.push({nRx,nRy,nBx,nBy});
        if(visited[nRx][nRy][nBx][nBy]<=10&&nRx==gx&&nRy==gy){
            cout<<visited[nRx][nRy][nBx][nBy];
            exit(0); 
        }
    }
}

void right(vector<vector<vector<vector<int>>>>& visited, vector<string>& map){
    int Rx = get<0>(q.front());
    int Ry = get<1>(q.front());
    int Bx = get<2>(q.front());
    int By = get<3>(q.front());
    
    nRx=Rx;nRy=Ry;nBx=Bx;nBy=By;
    
    if(Ry>=By){
        while(nRy+1 < visited[0].size() && map[nRx][nRy+1]!='#'){
            nRy++;
            if(nRx==gx&&nRy==gy) break;
        }
        
        while(nBy+1 < visited[0].size() && map[nBx][nBy+1]!='#'){
            nBy++;
            if(nBx==gx&&nBy==gy) return;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRy - Ry);
            int bdist = abs(nBy - By);
            if(rdist>bdist) nRy--;
            else nBy--;
        }
    }
    else{
        while(nBy+1 < visited[0].size() && map[nBx][nBy+1]!='#'){
            nBy++;
            if(nBx==gx&&nBy==gy) return;
        }
        
        while(nRy+1 < visited[0].size() && map[nRx][nRy+1]!='#'){
            nRy++;
            if(nRx==gx&&nRy==gy) break;
        }
        
        if(nRx==nBx&&nRy==nBy && !(nRx==gx&&nRy==gy)){
            int rdist = abs(nRy - Ry);
            int bdist = abs(nBy - By);
            if(rdist>bdist) nRy--;
            else nBy--;
        }
    }
    
    if(visited[nRx][nRy][nBx][nBy]==-1){
        visited[nRx][nRy][nBx][nBy]=visited[Rx][Ry][Bx][By]+1;
        q.push({nRx,nRy,nBx,nBy});
        if(visited[nRx][nRy][nBx][nBy]<=10&&nRx==gx&&nRy==gy){
            cout<<visited[nRx][nRy][nBx][nBy];
            exit(0); 
        }
    }
}

void bfs(vector<vector<vector<vector<int>>>>& visited, vector<string>& map){
    while(!q.empty()){
        up(visited,map);
        down(visited,map);
        left(visited,map);
        right(visited,map);
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<string>map(N);
    // -1로 초기화 (방문하지 않은 상태)
    vector<vector<vector<vector<int>>>> visited(N, vector<vector<vector<int>>>(M, vector<vector<int>>(N, vector<int>(M,-1))));
    
    for(int i=0; i<N; i++){
        cin>>map[i];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]=='O'){
                gx=i;
                gy=j;
            }
            if(map[i][j]=='R'){
                sRx=i;
                sRy=j;
            }
            if(map[i][j]=='B'){
                sBx=i;
                sBy=j;
            }
        }
    }
    q.push({sRx,sRy,sBx,sBy});
    visited[sRx][sRy][sBx][sBy]=0;  // 시작점은 0
    bfs(visited, map);
    cout<<-1;
    
    return 0;
}