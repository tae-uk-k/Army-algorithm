#include<bits/stdc++.h>
using namespace std;

int N, M;
int num[9] = {0};    
int result[9];       

void BT(int level, int t) {
    if(level == M) {

        for(int i = 0; i < M; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = t; i <= N; i++) {
        if(num[i] == 0) {
            num[i] = 1;
            result[level] = i;   
            BT(level + 1, i);
            num[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    BT(0,1);
    return 0;
}