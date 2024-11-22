#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a;
        cin>>a;
        cout<<a[0]<<a[a.length()-1]<<endl;   
    }
    return 0;
}