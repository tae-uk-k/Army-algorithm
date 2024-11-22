#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    stack<int>num;
    int T;
    int sum = 0;
    cin>>T;
    int N;
    for(int i=0; i<T; i++){
        cin>>N;
        if(N==0){
            num.pop();
            continue;
        }
        num.push(N);
    }
    while (!num.empty()) {
        sum += num.top();  
        num.pop();         
    }
    cout<<sum;
    return 0;
}