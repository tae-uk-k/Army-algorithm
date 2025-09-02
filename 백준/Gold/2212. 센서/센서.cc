#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> sensor;
    priority_queue<int> pq;
    
    for(int i = 0; i < N; i++) {
        int s;
        cin >> s;
        sensor.push_back(s);
    }
     if (K >= N) {
        cout << 0;
        return 0;
    }
    sort(sensor.begin(), sensor.end());  
    
    for(int l = 0; l < sensor.size() - 1; l++) {  
        int len = sensor[l + 1] - sensor[l];      
        pq.push(len);
    }
    
    for(int j = 0; j < K - 1; j++) {
        pq.pop();
    }
    
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans;
    return 0;
}