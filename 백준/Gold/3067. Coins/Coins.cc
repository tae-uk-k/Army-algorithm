#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        vector<int> coins(N);
        
        for (int j = 0; j < N; j++) {
            cin >> coins[j];
        }
        
        cin >> M;
        vector<int> dp(M + 1, 0); 
        dp[0] = 1;  

        for (int coin : coins) {  
            for (int k = coin; k <= M; k++) { 
                dp[k] += dp[k - coin];
            }
        }

        cout << dp[M] << "\n";  
    }
    
    return 0;
}
