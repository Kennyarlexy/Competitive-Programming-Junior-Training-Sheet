#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[20];

int main() {
    fast_io();
    //use ll when possible!
    ll N, M;
    while (cin >> N >> M) {
        for (ll i = 0; i < M; i++) {
            cin >> A[i];
        }
        ll divisible = 0;
        for (ll i = 1; i < (1 << M); i++) {
            ll on = __builtin_popcount(i);
            ll lcm = 1;
            for (ll j = 0; j < M; j++) {
                if (i & (1 << j)) {
                    lcm = lcm * A[j] / __gcd(lcm, A[j]); 
                }
            }

            if (on % 2 == 1) {
                divisible += (N / lcm);
            } else {
                divisible -= (N / lcm);
            }
        }
        ll res = N - divisible;
        cout << res << "\n";
    }


    return 0;
}