#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string N;
        cin>>N;
        int sum=0;
        int count=0;
        for(int j : N){
            if(j=='O'){
                sum+=count+1;
                count++;
            }
            else{
                count=0;
            }
        }
        cout<<sum<<"\n";
    }

    return 0;
}