#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        bool a=true;
        int N;
        cin>>N;
        unordered_set<string>part_num;
        vector<string>phone_call(N);
        for(int k=0; k<N; k++){
            cin>>phone_call[k];
        }
        sort(phone_call.begin(), phone_call.end(), greater<string>());
        for(int j=0; j<N; j++){
            string num= phone_call[j];
            if(!part_num.empty()&&part_num.find(num) != part_num.end()){
                a=false;
                break;
            }
            else{
                string subset;
                for(char s: num){
                    subset+=s;
                    part_num.insert(subset);
                }
            }
        }
        if(a) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    
    return 0;
}