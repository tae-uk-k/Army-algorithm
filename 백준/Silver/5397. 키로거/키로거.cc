#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        string S;
        cin>>S;
        
        stack<char> PW;
        stack<char> save;
        stack<char> print;
        
        for(char j : S){
            if(j=='<'){
                if(!PW.empty()){
                    save.push(PW.top());
                    PW.pop();
                }
                continue;
            }
            if(j=='>'){
                if(!save.empty()){
                    PW.push(save.top());
                    save.pop();
                }
                continue;
            }
            if(j=='-'){
                if(!PW.empty()){
                    PW.pop();
                }
                continue;
            }
            PW.push(j);
        }
        
        while(!PW.empty()){
            print.push(PW.top());
            PW.pop();
        }
        while(!print.empty()){
            cout<<print.top();
            print.pop();
        }
        while(!save.empty()){
            cout<<save.top();
            save.pop();
        }
        cout<<"\n";
    }
    return 0;
}