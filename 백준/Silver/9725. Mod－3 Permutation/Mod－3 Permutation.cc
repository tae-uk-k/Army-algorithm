#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    for(int i=1; i<=T; i++){
        int N;
        cin>>N;
        int zero_two=0, zero_one=0, two_zero=0, two_one=0, one_two=0, one_zero=0;
        int ans=0;
        for(int j=0; j<N; j++){
            int num;
            cin>>num;
            if(j%3==0){
                if(num%3==2)zero_two++;
                else if(num%3==1)zero_one++;
            }
            if(j%3==1){
                if(num%3==0)one_zero++;
                else if(num%3==2)one_two++;
            }
            if(j%3==2){
                if(num%3==0)two_zero++;
                else if(num%3==1)two_one++;
            }
        }
        if(zero_one>=one_zero){
            ans+=one_zero;
            zero_one-=one_zero;
            one_zero=0;
        }
        else{
            ans+=zero_one;
            one_zero-=zero_one;
            zero_one=0;
        }
        if(zero_two>=two_zero){
            ans+=two_zero;
            zero_two-=two_zero;
            two_zero=0;
        }
        else{
            ans+=zero_two;
            two_zero-=zero_two;
            zero_two=0;
        }
        if(two_one>=one_two){
            ans+=one_two;
            two_one-=one_two;
            one_two=0;
        }
        else{
            ans+=two_one;
            one_two-=two_one;
            two_one=0;
        }
        
        if(zero_one==0)ans+=one_zero*2;
        else if(one_zero==0)ans+=zero_one*2;
        cout<<"Case #"<<i<<": "<<ans<<"\n";
        //cout<<zero_two<< zero_one<< two_zero<< two_one<< one_two<< one_zero<<"\n";
    }
    return 0;
}







