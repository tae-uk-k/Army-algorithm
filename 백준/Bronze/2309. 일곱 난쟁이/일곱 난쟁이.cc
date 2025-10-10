#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>lenth(9);
    for(int i=0; i<9; i++){
        cin>>lenth[i];
    }
    sort(lenth.begin(),lenth.end());
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            int sum=0;
            for(int l=0; l<9; l++){
                if(l==i||l==j)continue;
                sum+=lenth[l];
            }

            if(sum==100){
                for(int k=0; k<9; k++){
                    if(k==i||k==j)continue;
                    cout<<lenth[k]<<"\n";
                }
                return 0;
            }
        }
    }
    return 0;
}