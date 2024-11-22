#include <iostream>
#define REPEAT(count) for (int k = 0; k < (count); ++k)
using namespace std;

int main() {
    int a;
    cin>>a;
    for(int i=a-1,j=1; i>=0;i--,j+=2){
        REPEAT(i) {
            cout<<' ';
        }
        REPEAT(j){
            cout<<'*';
        }
        cout<<"\n";
    }
    for(int f=1,h=a*2-3;f<=a-1;f++,h-=2){
        REPEAT(f) {
            cout<<' ';
        }
        REPEAT(h) {
            cout<<'*';
        }
        cout<<"\n";
    }
}