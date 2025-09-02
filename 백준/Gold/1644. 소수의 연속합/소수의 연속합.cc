#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int ans = 0, start = 0, end = 0;
    int sum = 0;
    cin>>N;
    vector<int>prime;
    vector<bool> is_prime(N + 1, true);
    is_prime[0]=is_prime[1]=0;
    
    if (N == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 2; i * i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
        
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            prime.push_back(i);
        }
    }    
    
    while (end <= prime.size()) {
        if (sum >= N) {
            sum -= prime[start];
            start++;
        }
        if (sum < N) {
            sum += prime[end];
            end++;
        }
        if (sum == N) ans++;
    }
    cout << ans;
    return 0;
}