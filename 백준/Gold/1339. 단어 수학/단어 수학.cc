#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<string> words(N);
    vector<int> weight(26, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    for(int i = 0; i < N; i++) {
        int len = words[i].length();
        for(int j = 0; j < len; j++) {
            char ch = words[i][j];
            int power = len - j - 1;
            weight[ch - 'A'] += pow(10, power);
        }
    }
    
    vector<pair<int, int>> alphabet_weight;
    for(int i = 0; i < 26; i++) {
        if(weight[i] > 0) {
            alphabet_weight.push_back({weight[i], i});
        }
    }
    
    sort(alphabet_weight.begin(), alphabet_weight.end(), greater<pair<int, int>>());
    
    vector<int> alphabet_num(26, 0);
    int num = 9;
    for(auto& p : alphabet_weight) {
        alphabet_num[p.second] = num--;
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int value = 0;
        for(int j = 0; j < words[i].length(); j++) {
            char ch = words[i][j];
            value = value * 10 + alphabet_num[ch - 'A'];
        }
        ans += value;
    }
    
    cout << ans << "\n";
    
    return 0;
}