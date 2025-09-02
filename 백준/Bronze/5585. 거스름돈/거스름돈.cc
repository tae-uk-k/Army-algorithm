#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    int ans=0;
    int coin[6]={500,100,50,10,5,1};
    n=1000-n;
    for(int i : coin){
        while(n>=i){
            n-=i;ans++;
            if(n==0){
                cout<<ans;
                return 0;
            }
        }
    }
    return 0;
}