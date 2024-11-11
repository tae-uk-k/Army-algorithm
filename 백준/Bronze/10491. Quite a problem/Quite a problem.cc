#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype> 
using namespace std;

int main() {
    string S;
    while(getline(cin,S)){
        std::transform(S.begin(), S.end(), S.begin(), ::tolower);
        if(S.find("problem")==std::string::npos){
            cout<<"no"<<"\n";
        }
        else{
            cout<<"yes"<<"\n";
        }
    }
    return 0;
}