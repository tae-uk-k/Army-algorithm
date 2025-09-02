#include <bits/stdc++.h>
using namespace std;
//정답 보고 풀었음 나중에 다시 보기 
const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    int power[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int dp[101][10][1024] = {};
    for (int digit = 1; digit <= 9; digit++) {
        dp[1][digit][power[digit]] = 1;
    }
    for (int len = 1; len < n; len++) {
        for (int last = 0; last <= 9; last++) {
            for (int mask = 0; mask < 1024; mask++) {
                if (dp[len][last][mask] == 0) continue;
                
                if (last > 0) {
                    int next_digit = last - 1;
                    int next_mask = mask | power[next_digit];
                    dp[len + 1][next_digit][next_mask] += dp[len][last][mask];
                    dp[len + 1][next_digit][next_mask] %= MOD;
                }
                
                if (last < 9) {
                    int next_digit = last + 1;
                    int next_mask = mask | power[next_digit];
                    dp[len + 1][next_digit][next_mask] += dp[len][last][mask];
                    dp[len + 1][next_digit][next_mask] %= MOD;
                }
            }
        }
    }
    int answer = 0;
    for (int last = 0; last <= 9; last++) {
        answer += dp[n][last][1023];
        answer %= MOD;
    }
    cout << answer << "\n";
    return 0;
}