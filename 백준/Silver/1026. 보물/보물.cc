#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() { int N; int a,b; int sum=0;

vector<int>A;
vector<int>B;

cin >> N;

for (int i=0;i<N;i++){
    cin>>a;
    A.push_back(a);
}

for (int j=0;j<N;j++){
    cin>>b;
    B.push_back(b);
}

sort(A.begin(), A.end());
sort(B.begin(), B.end(), greater<int>());

for (int k=0;k<N;k++){
    sum+=A[k]*B[k];
}

cout<<sum;

return 0;
}

