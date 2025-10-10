#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> num(101, 0);
int result = 0;

bool Check(int x, int y, int z) {
    num[x]++; 
    num[y]++; 
    num[z]++;
    
    bool flag = false;
    for(int i : {x, y, z}) {
        if(num[i] == 1) {
            bool hasLarger = false;
            for(int j = i + 1; j <= 100; j++) {
                if(num[j] == 1) {
                    hasLarger = true;
                    break;
                }
            }
            if(!hasLarger) {
                flag = true;
                break;
            }
        }
    }
    
    num[x]--; 
    num[y]--; 
    num[z]--;
    return flag;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N * 3; i++) {
        int a;
        cin >> a;
        num[a]++;
    }
    
    for(int i = 1; i <= 100; i++) {
        for(int j = i + 1; j <= 100; j++) {
            for(int k = j + 1; k <= 100; k++) {
                if(Check(i, j, k)) {
                    result++;
                }
            }
        }
    }
    
    cout << result;
    return 0;
}