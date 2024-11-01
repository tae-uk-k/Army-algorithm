#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int N,K;
    int j=1;
    queue<int>Q;
    
    cin>>N>>K;
    cout<<'<';
    
    for(int i=1;i<=N;i++){
        Q.push(i);
    }
    
    while(!Q.empty()){
        if(j%K==0){
            cout<<Q.front();
            Q.pop();
            if(!Q.empty()){
            cout<<", ";
            }
        }
        else{
            Q.push(Q.front());
            Q.pop();
        }
        j++;
    }
    cout<<'>';
    return 0;
}
