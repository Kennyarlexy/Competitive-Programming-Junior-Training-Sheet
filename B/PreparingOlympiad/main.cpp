#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[20];

int main() {
    ll n, l, r, x;
    fast_io();
    //use ll when possible!
    cin >> n >> l >> r >> x;

    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll cnt = 0;
    for (ll k = 1; k < (1 << n); k++) {
        ll onBit = __builtin_popcount(k);
        if (onBit == 1) continue;

        ll total = 0;
        ll minim = LONG_LONG_MAX;
        ll maxim = 0;
        for (ll i = 0; i < n; i++) {
            if (k & (1 << i)) {
                total += A[i];
                minim = min(minim, A[i]);
                maxim = max(maxim, A[i]);
            }
        }

        if (total >= l && total <= r && maxim - minim >= x) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}