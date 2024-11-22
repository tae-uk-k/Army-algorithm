#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    int T=a*b*c;
    vector<int>num(10,0);
    string S=to_string(T);
    for(char i:S){
        int num1 = i - '0';
        num[num1]++;
    }
    for(int j=0;j<10;j++){
        cout<<num[j]<<endl;
    }
    return 0;
}