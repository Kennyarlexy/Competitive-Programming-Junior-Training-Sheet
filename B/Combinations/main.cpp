#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    while (true) {
        int N, M; cin >> N >> M;
        if (M == 0 && N == 0) break;

        int a = N, b = N-M, k = M;
        if (b < k) swap(b, k);
        ll result = 1;
        int temp = 2;
        //iterate [a, b), while divisible by temp, divide and increment until k
        for (int start = a; start > b; start--) {
            result *= start;
            while (result % temp == 0 && temp <= k) {
                result /= temp;
                temp++;
            }
        }
        cout << N << " things taken " << M << " at a time is " << result << " exactly.\n";
    }

    return 0;
}