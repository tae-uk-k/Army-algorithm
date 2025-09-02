#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;

void build(vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    long long left_sum = query(2 * node, start, mid, left, right);
    long long right_sum = query(2 * node + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

void update(int node, int start, int end, int idx, int new_val) {
    if(start == end){
        tree[node] = new_val;
    } 
    else{
        int mid = (start + end) / 2;
        if(idx <= mid){
            update(2 * node, start, mid, idx, new_val);
        } 
        else{
            update(2 * node + 1, mid + 1, end, idx, new_val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> arr(N);
    tree.resize(4 * N);
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    build(arr, 1, 0, N - 1);
    
    for(int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        
        int left = min(x, y) - 1;
        int right = max(x, y) - 1;
        
        cout << query(1, 0, N - 1, left, right) << "\n";
        update(1, 0, N - 1, a - 1, b);
    }
    
    return 0;
}