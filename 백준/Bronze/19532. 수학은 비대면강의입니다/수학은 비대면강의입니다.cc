#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f,X,Y;
    cin >> a >> b >> c >> d >> e >> f;
    if(b==0){
        X=c/a;
        Y=(-d*X+f)/e;
        cout<<X<<' '<<Y;
        return 0;
    }
    for (int x = -999; x <= 999; x++) {
        int y1 = (c - a * x) / b;

        if (a * x + b * y1 == c && d * x + e * y1 == f) {
            cout << x << " " << y1 << endl;
            break; 
        }
    }

    return 0;
}
