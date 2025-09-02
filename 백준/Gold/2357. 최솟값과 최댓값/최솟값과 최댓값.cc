#include <bits/stdc++.h>
using namespace std;

vector<int> treeMin;
vector<int> treeMax;
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
void buildMax(vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        treeMax[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildMax(arr, 2 * node, start, mid);
        buildMax(arr, 2 * node + 1, mid + 1, end);
        treeMax[node] = max(treeMax[2 * node], treeMax[2 * node + 1]);
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
int queryMax(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return treeMax[node];
    }
    
    int mid = (start + end) / 2;
    int left_min = queryMax(2 * node, start, mid, left, right);
    int right_min = queryMax(2 * node + 1, mid + 1, end, left, right);
    return max(left_min, right_min);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> arr(N);
    vector<pair<int, int>>range(M);
    vector<pair<int, int>>ans;
    treeMin.resize(4 * N);
    treeMax.resize(4 * N);
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int j=0; j<M; j++){
        cin>>range[j].first;
        cin>>range[j].second;
    }
    
    buildMin(arr, 1, 0, N - 1);
    buildMax(arr, 1, 0, N - 1);
    
    
    for(int k=0; k<M; k++){
        auto[start, end]=range[k];
        int a=queryMin(1, 0, N-1, start-1, end-1);
        int b=queryMax(1, 0, N-1, start-1, end-1);
        ans.push_back({a,b});
    }
    
    for(auto[m, M] : ans){
        cout<<m<<' '<<M<<"\n";
    }
    return 0;
}







