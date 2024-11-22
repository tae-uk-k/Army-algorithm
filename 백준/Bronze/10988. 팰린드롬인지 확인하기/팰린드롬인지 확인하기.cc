#include <iostream>
#include <string>
using namespace std;

int main() {
    string T;
    cin>>T;
    if(T.size()%2==1){
        T.erase(T.size()/2,1);
    }
    for(int i=0;i<T.size()/2;i++){
        if(T[i]!=T[T.size()-1-i]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}