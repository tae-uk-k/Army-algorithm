#include <iostream>
#include <cmath>
using namespace std;

int main() { int T,X1,Y1,R1,X2,Y2,R2,sR,bR; float dif; cin>>T; for(int i=0;i<T;i++){ cin>>X1>>Y1>>R1>>X2>>Y2>>R2;

    dif=sqrt(pow(X1-X2,2)+pow(Y1-Y2,2));
    R1 > R2 ? (bR = R1, sR = R2) : (bR = R2, sR = R1);

    if(X1==X2&&Y1==Y2&&R1==R2){
        cout<<-1<<"\n";
    }
    else if(dif+sR<bR||sR+bR<dif){
        cout<<0<<"\n";
    }
    else if(dif==sR+bR||dif+sR==bR){
        cout<<1<<"\n";
    }
    else if(dif<sR+bR||dif+sR>bR){
        cout<<2<<"\n";
    }
}
return 0;
}