#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    int count=0;
    string S;
    stack<char>LRskil;
    stack<char>SKskil;
    cin>>T>>S;
    for(int i=0;i<T;i++){
        char A=S[i];
        if(A=='L'){
            LRskil.push(A);
        }
        if(A=='S'){
            SKskil.push(A);
        }
        else if(!LRskil.empty()&&A=='R'&&LRskil.top()=='L'){
            LRskil.pop();
            count++;
        }
        else if(!SKskil.empty()&&A=='K'&&SKskil.top()=='S'){
            SKskil.pop();
            count++;
        }
        else if(A=='R'&&LRskil.empty()){
            break;
        }
        else if(A=='K'&&SKskil.empty()){
            break;
        }
        else if(A=='1'||A=='2'||A=='3'||A=='4'||A=='5'||A=='6'||A=='7'||A=='8'||A=='9'){
            count++;
        }
    }
    cout<<count;
    return 0;
}
