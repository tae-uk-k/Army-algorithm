#include <iostream>
using namespace std;

int main() {
    int a,b;
    int sum=0;
    cin>>a;
    while (cin >> b){
        if(a==b)
            sum++;
    }
    cout<<sum;
    return 0;
}