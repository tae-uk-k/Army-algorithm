#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    vector<int> sum;
    int S = 0;

    for (int c : num) {
        S += c;
        if (S < 0) S = 0;
        sum.push_back(S);
    }

    sort(sum.begin(), sum.end());
    
    if(sum.back()==0){
        sort(num.begin(), num.end());
        cout<<num.back();
        return 0;
    }

    cout << sum.back();
    return 0;
}
