#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A_size, B_size, A_n, B_n;
    cin>>A_size>>B_size;
    
    unordered_set<int>A;
    unordered_set<int>B;
    unordered_set<int>U;
    
    for(int i=0;i<A_size;i++){
        cin>>A_n;
        A.insert(A_n);
        U.insert(A_n);
    }
    for(int j=0;j<B_size;j++){
        cin>>B_n;
        B.insert(B_n);
        U.insert(B_n);
    }
    for(int k : A){
        if(B.count(k)==1){
            U.erase(k);
        }
    }
    
    cout<<U.size();
    
    return 0;
}