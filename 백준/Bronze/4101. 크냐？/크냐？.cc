#include <iostream>

using namespace std;




int main(void)
{
    int A, B;

    while (1)
    {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        else
        {
        
        if (A > B)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
      }
    return 0;
}