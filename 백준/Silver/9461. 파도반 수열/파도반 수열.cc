#include <iostream>

using namespace std;

int main() {
    int T,c;
    long long num[200]={0,1,1,1,2,2,3,4,5,7,9,12};
    
    for(int j=10;j<101;j++){
        num[j]=num[j-2]+num[j-3];
    }
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>c;
        cout<<num[c]<<"\n";
    }
    return 0;
}