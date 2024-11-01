#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double N;
    long double sum=0;
    
    cin>> N;
    
    for(long double i=0; i<N; i+=1){
        sum+=N/(N-i);
    }
    std::cout << std::fixed << std::setprecision(20);
    cout<<sum;
    return 0;
}