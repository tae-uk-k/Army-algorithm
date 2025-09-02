#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    priority_queue<int> pos;
    priority_queue<int, vector<int>, greater<int>> neg;
    int ones=0, zeros= 0;
    
    for (int i=0; i<n; i++) {
        int x;cin >> x;
        
        if (x > 1) pos.push(x);
        else if (x ==1) ones++;
        else if (x ==0) zeros++;
        else neg.push(x);
    }
    
    long long ans =0;
    
    while (pos.size()>=2) {
        int a=pos.top(); pos.pop();
        int b=pos.top(); pos.pop();
        ans +=a*b;
    }
    if (!pos.empty()) {
        ans+=pos.top();
    }
    
    while (neg.size()>= 2) {
        int a =neg.top(); neg.pop();
        int b= neg.top(); neg.pop();
        ans += a*b;
    }
    if (!neg.empty()) {
        if (zeros >0) {
            
        } 
        else {
            ans +=neg.top();
        }
    }
    ans+=ones;
    cout <<ans;
    
    return 0;
}