#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    while (true) {
        int N; cin >> N;
        if (N == 0) break;
        int num[N+1];
        for (int i = 1; i <= N; i++) {
            cin >> num[i];
        }
        int A = 0;
        for (int i = 1; i < N; i++) {
            for (int j = i+1; j <= N; j++) {
                if (__gcd(num[i], num[j]) == 1) A++; 
            }
        }

        int a = N, b = N-2, k = 2;
        if (b < k) swap(b, k);
        ll B = 1;
        int temp = 2;
        //iterate [a, b), while divisible by temp, divide and increment until k
        for (int start = a; start > b; start--) {
            B *= start;
            while (B % temp == 0 && temp <= k) {
                B /= temp;
                temp++;
            }
        }
        if (A > 0) {
            double pi = sqrt(6.0*B / A);
            cout << fixed << setprecision(6) << pi << "\n";
        } else {
            cout << "No estimate for this data set.\n";
        }
    }

    return 0;
}