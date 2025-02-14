#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    int sum=0;
    cin >> N;
    
    vector<pair<int, int>> W(N);
    vector<int> order(1001, -1);
    
    for (int i = 0; i < N; i++) {
        cin >> W[i].first >> W[i].second;
    }
    
    sort(W.begin(), W.end(), [](const pair<int, int>& a, const pair<int, int>& b) {  
        if (a.second == b.second) return a.first > b.first;  
        return a.second > b.second;  
    });

    for (int i = 0; i < N; i++) {
        int idx = W[i].first;
        while (idx > 0 && order[idx] != -1) idx--;
        if (idx > 0) order[idx] = W[i].second;
    }
    
    for(int j : order){
        if(j!=-1)sum+=j;
    }
    
    cout<<sum;
    return 0;
}
