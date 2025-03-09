#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int optimal = 0;
int sum;

bool ispossible(vector<int>& budgets) {
    int payment = 0;
    for (int i : budgets) {
        if (i > optimal) payment += optimal;
        else payment += i;
    }
    return payment <= sum;
}

int main() {
    int N, budget;
    int Max = 0;
    
    cin >> N;
    vector<int> budgets;
    for (int i = 0; i < N; i++) {
        cin >> budget;
        budgets.push_back(budget);
        if (Max < budget) Max = budget;
    }
    cin >> sum;
    
    int Min = sum / budgets.size();
    
    while (Min <= Max) {
        optimal = (Min + Max) / 2;
        if (ispossible(budgets)) Min = optimal + 1;
        else Max = optimal - 1;
    }

    cout << Max;
    return 0;
}
