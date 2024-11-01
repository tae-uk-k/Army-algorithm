#include <bits/stdc++.h>

using namespace std;

int main() {
    string a,b;
    cin >> a;
    b=a;
    vector<string>c(a.size());
    
    for(int i=0;i<a.size();i++){
        c[i]=b;
        b.erase(0,1);
    }
    
    sort(c.begin(), c.end());
    for (const string& word : c) {
        std::cout << word << std::endl;
    }
    
    
    return 0;
}