#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K; 
    cin >> K;
    int total = (1 << K) - 1;
    
    vector<int> inorder(total);
    for (int i = 0; i < total; i++){
        cin >> inorder[i];
    }
    
    vector<vector<int>> levels;
    
    vector<int> current = inorder;

    while (current.size() > 1) {

        vector<int> extracted;
        for (int i = 0; i < current.size(); i += 2) {
            extracted.push_back(current[i]);
        }

        levels.push_back(extracted);
        
        vector<int> remaining;
        for (int i = 1; i < current.size(); i += 2) {
            remaining.push_back(current[i]);
        }
        current = remaining; 
    }
    
    if (!current.empty()){
        levels.push_back(current);
    }
    
    reverse(levels.begin(), levels.end());
    
    for (auto &lev : levels) {
        for (int num : lev) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
