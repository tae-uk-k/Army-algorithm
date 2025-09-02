#include <bits/stdc++.h>
using namespace std;

long long countOnes(long long n) {
    long long count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

bool isLastSixZero(long long n) {
    return (n & 63) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long sum = 0;
    long long A, B;
    cin >> A >> B;
    
    long long n = A;
    
    // 첫 번째: 끝 6비트가 000000이 될 때까지
    while (!isLastSixZero(n) && n <= B) {
        sum += countOnes(n);
        n++;
    }
    
    // 두 번째: 64개씩 묶어서 처리 (끝 6비트가 000000인 경우)
    while (n + 63 <= B && isLastSixZero(n)) {
        long long commonPart = countOnes(n);
        
        // 더 큰 블록(2^27)으로 처리 가능한지 확인
        if (n + 134217727 <= B && (n & 134217727) == 0) {
            sum += commonPart * 134217728 + 1811939328;
            n += 134217728;
        } else {
            sum += commonPart * 64 + 192;
            n += 64;
        }
    }
    
    // 나머지 처리
    while (n <= B) {
        sum += countOnes(n);
        n++;
    }
    
    cout << sum;
    return 0;
}