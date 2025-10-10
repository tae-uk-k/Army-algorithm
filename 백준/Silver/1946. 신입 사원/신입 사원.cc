#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> N;
        vector<pair<int,int>> score(N);
        
        for(int j = 0; j < N; j++) {
            cin >> score[j].first >> score[j].second;
        }
        
        sort(score.begin(), score.end()); 
        
        int count = 1; 
        int min_interview = score[0].second; 
        
        for(int k = 1; k < N; k++) {
            
            if(score[k].second < min_interview) {
                count++;
                min_interview = score[k].second; 
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}