#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        int N, K, W;
        cin >> N >> K;
        
        vector<vector<int>> building_order(N + 1, vector<int>());
        vector<int> building_delay(N + 1);
        vector<int> indegree(N + 1, 0);
        
        for(int i = 1; i <= N; i++){
            cin >> building_delay[i];
        }
        
        for(int j = 0; j < K; j++){
            int x, y;
            cin >> x >> y;
            building_order[x].push_back(y);
            indegree[y]++;
        }
        
        cin >> W;
        
        vector<int> max_time(N + 1, 0);
        queue<int> q;
        
        for(int i = 1; i <= N; i++){
            if(indegree[i] == 0){
                q.push(i);
                max_time[i] = building_delay[i];
            }
        }
        
        while(!q.empty()){
            int current = q.front();
            q.pop();
            
            for(int next : building_order[current]){
                max_time[next] = max(max_time[next], max_time[current] + building_delay[next]);
                indegree[next]--;
                
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        
        cout << max_time[W] << "\n";
    }
    
    return 0;
}