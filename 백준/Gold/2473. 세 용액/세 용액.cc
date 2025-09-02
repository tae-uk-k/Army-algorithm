#include <bits/stdc++.h>
using namespace std;
const int INF = 5001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long solution[INF];
    long long result[3];
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> solution[i];
    }
    sort(solution, solution + N);
    long long minSum = LLONG_MAX;
    
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;
        
        while (left < right) {
            long long tmp = solution[i] + solution[left] + solution[right];
            
            if (abs(tmp) < abs(minSum)) {
                minSum = tmp;
                result[0] = solution[i];
                result[1] = solution[left];
                result[2] = solution[right];
            }
            
            if (tmp < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    cout << result[0] << " " << result[1] << " " << result[2] << "\n";
    return 0;
}