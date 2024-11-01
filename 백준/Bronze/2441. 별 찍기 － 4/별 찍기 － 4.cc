#include <iostream>

using namespace std;

int main()
{
    int numRows;

    // 입력받기
    cin >> numRows;

    // 행 반복
    for (int row = 0; row < numRows; row++)
    {
        // 공백 출력
        for (int space = 0; space < row; space++)
        {
            cout << " ";
        }
        // 별 출력
        for (int star = numRows; star > row; star--)
        {
            cout << "*";
        }
        cout << "\n"; // 줄바꿈
    }
}