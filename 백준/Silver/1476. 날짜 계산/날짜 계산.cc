#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    int a2=1;
    int b2=1;
    int c2=1;
    cin >> a >> b>>c;

    for(int i=1;i<7981;i++){
        if(a==a2&&b==b2&&c==c2){
            cout<<i;
            return 0;
        }
        a2+=1;
        b2+=1;
        c2+=1;
        if(a2>15){
            a2-=15;
        }
        if(b2>28){
            b2-=28;
        }
        if(c2>19){
            c2-=19;
        }
    }
    return 0;
}