#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    int a=0,c=0;
    for(int i=1;i<=N;i++){
        a+=i;
        c+=i*i*i;
    }
    cout<<a<<"\n"<<a*a<<"\n"<<c;
    return 0;
}