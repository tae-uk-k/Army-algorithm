#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string A;
    for(int i=0; i<8; i++){
        string c;
        cin>>c;
        A.append(c);
    }
    if(A=="12345678")
        cout<<"ascending";
    else if(A=="87654321")
        cout<<"descending";
    else
        cout<<"mixed";
    return 0;
}