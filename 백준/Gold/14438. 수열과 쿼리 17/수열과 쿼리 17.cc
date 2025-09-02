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
void update(int node, int start, int end, int idx, int new_val) {
    if(start == end){
        treeMin[node] = new_val;
    } 
    else{
        int mid = (start + end) / 2;
        if(idx <= mid){
            update(2 * node, start, mid, idx, new_val);
        } 
        else{
            update(2 * node + 1, mid + 1, end, idx, new_val);
        }
        treeMin[node] = min(treeMin[2 * node] , treeMin[2 * node + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int N,M;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cin>>M;
    treeMin.resize(4 * N);
    buildMin(arr, 1, 0, N - 1);
    
    int A,B,C;
    for(int j=0; j<M; j++){
        cin>>A>>B>>C;
        if(A==1){
            update(1, 0, N-1, B-1, C);
        }
        else{
            cout<<queryMin(1, 0, N-1, B-1, C-1)<<"\n";
        }
    }
    return 0;
}







