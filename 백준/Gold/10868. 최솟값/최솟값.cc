#include <bits/stdc++.h>
using namespace std;

vector<int> treeMin;
const int INF = 1e9;

void buildMin(vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        treeMin[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildMin(arr, 2 * node, start, mid);
        buildMin(arr, 2 * node + 1, mid + 1, end);
        treeMin[node] = min(treeMin[2 * node], treeMin[2 * node + 1]);
    }
}


int queryMin(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return INF;
    }
    if (left <= start && end <= right) {
        return treeMin[node];
    }
    
    int mid = (start + end) / 2;
    int left_min = queryMin(2 * node, start, mid, left, right);
    int right_min = queryMin(2 * node + 1, mid + 1, end, left, right);
    return min(left_min, right_min);
}


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> arr(N);
    vector<pair<int, int>>range(M);
    vector<int>ans;
    treeMin.resize(4 * N);
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int j=0; j<M; j++){
        cin>>range[j].first;
        cin>>range[j].second;
    }
    
    buildMin(arr, 1, 0, N - 1);
    
    for(int k=0; k<M; k++){
        auto[start, end]=range[k];
        int a=queryMin(1, 0, N-1, start-1, end-1);
        ans.push_back(a);
    }
    
    for(int m : ans){
        cout<<m<<"\n";
    }
    return 0;
}







