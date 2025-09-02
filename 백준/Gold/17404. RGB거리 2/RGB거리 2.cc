#include <bits/stdc++.h>
using namespace std;

int INF = 987654321;

int main() {
    int N;
    cin >> N;
    
    int RGB[1001][3];
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> RGB[i][j];
        }
    }
    
    int ans1[1001][3];  
    int ans2[1001][3];  
    int ans3[1001][3];  
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < 3; j++){
            ans1[i][j] = ans2[i][j] = ans3[i][j] = INF;
        }
    }
    
    ans1[1][0] = RGB[1][0]; 
    ans2[1][1] = RGB[1][1];  
    ans3[1][2] = RGB[1][2];  
    
    for(int i = 2; i <= N; i++){
        
        ans1[i][0] = min(ans1[i-1][1], ans1[i-1][2]) + RGB[i][0];
        ans1[i][1] = min(ans1[i-1][0], ans1[i-1][2]) + RGB[i][1];
        ans1[i][2] = min(ans1[i-1][0], ans1[i-1][1]) + RGB[i][2];
        
        ans2[i][0] = min(ans2[i-1][1], ans2[i-1][2]) + RGB[i][0];
        ans2[i][1] = min(ans2[i-1][0], ans2[i-1][2]) + RGB[i][1];
        ans2[i][2] = min(ans2[i-1][0], ans2[i-1][1]) + RGB[i][2];
        
        ans3[i][0] = min(ans3[i-1][1], ans3[i-1][2]) + RGB[i][0];
        ans3[i][1] = min(ans3[i-1][0], ans3[i-1][2]) + RGB[i][1];
        ans3[i][2] = min(ans3[i-1][0], ans3[i-1][1]) + RGB[i][2];
    }
    
    int result = INF;
    result = min(result, min(ans1[N][1], ans1[N][2]));  
    result = min(result, min(ans2[N][0], ans2[N][2]));  
    result = min(result, min(ans3[N][0], ans3[N][1]));  
    
    cout << result << "\n";
    
    return 0;
}