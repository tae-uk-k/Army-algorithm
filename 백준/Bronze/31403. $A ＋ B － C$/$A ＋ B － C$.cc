#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << "\n";

    string strA = to_string(a);
    string strB = to_string(b);
    int combinedResult = stoi(strA + strB) - c;

    cout << combinedResult << "\n";
    return 0;
}
