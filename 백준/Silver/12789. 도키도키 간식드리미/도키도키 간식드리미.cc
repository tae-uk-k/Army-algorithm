#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N, a;
    cin >> N;
    queue<int> student;
    stack<int> temp;

    for (int i = 0; i < N; i++) {
        cin >> a;
        student.push(a);
    }

    for (int j = 1; j <= N; ) {
        if (!student.empty() && j == student.front()) {
            student.pop();
            j++;
        }
        else if (!temp.empty() && j == temp.top()) {
            temp.pop();
            j++;
        }
        else if (!student.empty()) {
            temp.push(student.front());
            student.pop();
        }
        else {
            break;
        }
    }

    if (temp.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
    return 0;
}
