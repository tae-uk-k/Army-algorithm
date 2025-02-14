#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> node(100001);
vector<bool> visited(100001, 0);
vector<int> root(100001, -1);
// 2차원 벡터 3개를 사용하자.
//하나는 입력을 받고, 하나는 방문 여부를 판단하고, 하나는 부모 노드를 저장해주자.

//node[1]에 있는 수부터 부모를 1인걸로 저장해주자. 그리고 그 수를 큐에 넣는다. 
//node[큐의 front]에 있는 수 중에서 방문하지 않은 수는 부모가 큐의 front인걸로 하고 pop한다.
void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : node[cur]) {
            if (visited[next]) continue;
            root[next] = cur;
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, a, b;
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    bfs();
    
    for (int k = 2; k <= N; k++) {
        cout << root[k] << "\n";
    }
}
