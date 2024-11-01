#include <iostream>

using namespace std;

int main() {
    long long a;
    long long sum=0;
    long long p=0;
    int count=0;
    cin>>a;
    
    while(sum<=a){
        ++p;
        sum+=p;
        count++;
    }
    cout<<count-1;
    return 0;
}
