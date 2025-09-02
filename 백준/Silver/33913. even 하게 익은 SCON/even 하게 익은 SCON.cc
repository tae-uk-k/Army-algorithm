#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    
    int n;
    cin>>n;
    
    long long even=1,odd=0;
    
    for(int i=0;i<n;i++) {
        long long ne=(even*24+odd*2)%MOD;
        long long no=(odd*24+even*2)%MOD;
        even=ne;
        odd=no;
    }
    
    cout<<even<<"\n";
    
    return 0;
}