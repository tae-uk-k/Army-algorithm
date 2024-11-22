#include <iostream>

using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int H,W,N;
        cin>>H>>W>>N;
        if(N%H==0){
            cout<<H;
            cout.width(2);
            cout.fill('0');
            cout<<N/H<<"\n";}
        else{
            cout<<N%H;
            cout.width(2);
            cout.fill('0');
            cout<<N/H+1<<"\n";}
    }
    return 0;
}