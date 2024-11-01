#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int W, H, X, Y, P, pX, pY, rX1, rY1, rX2, rY2, r;
    int count=0;
    
    cin>>W >>H >>X >>Y >>P;
    
    rX1=X;
    rY1=Y+H/2;
    rX2=X+W;
    rY2=Y+H/2;
    r=H/2;
    
    for(int i=0;i<P;i++){
        cin>>pX>>pY;
        if(X<=pX&&pX<=X+W&&Y<=pY&&pY<=Y+H){
            count++;
            continue;
        }
        if(pow(rX1-pX,2)+pow(rY1-pY,2)<=pow(r,2)||pow(rX2-pX,2)+pow(rY2-pY,2)<=pow(r,2)){
            count++;
            continue;
        }
    }
    cout<<count;
    return 0;
}
