#include <iostream>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<int> dq;
    int N;
    std::cin >> N;

    while (N--) {
        int command;
        std::cin >> command;

        if (command == 1) {
            int X;
            std::cin >> X;
            dq.push_front(X);
        } else if (command == 2) {
            int X;
            std::cin >> X;
            dq.push_back(X);
        } else if (command == 3) {
            if (!dq.empty()) {
                std::cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                std::cout << -1 << '\n';
            }
        } else if (command == 4) {
            if (!dq.empty()) {
                std::cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                std::cout << -1 << '\n';
            }
        } else if (command == 5) {
            std::cout << dq.size() << '\n';
        } else if (command == 6) {
            std::cout << dq.empty() << '\n';
        } else if (command == 7) {
            if (!dq.empty()) {
                std::cout << dq.front() << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        } else if (command == 8) {
            if (!dq.empty()) {
                std::cout << dq.back() << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}
