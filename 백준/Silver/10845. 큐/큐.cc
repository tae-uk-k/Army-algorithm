#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int T,a;
    string com;
    cin>>T;
    queue<int>Q;
    
    for(int i=0;i<T;i++){
        cin>>com;
        if(com=="push"){
            cin>>a;
            Q.push(a);
        }
        if(com=="pop"){
            if (Q.empty()) {
                cout << -1 << "\n";
            } 
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        if(com=="size"){
            cout<<Q.size()<<"\n";
        }
        if(com=="empty"){
            cout << (Q.empty() ? 1 : 0 )<< "\n";
        }
        if(com=="front"){
            cout << (Q.empty() ? -1 : Q.front() )<< "\n";
        }
        if(com=="back"){
            cout << (Q.empty() ? -1 : Q.back() )<< "\n";
        }
    }
    
    return 0;
}