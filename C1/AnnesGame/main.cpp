#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll P(ll n, ll r) {
    if (n < r) return 0;

    ll res = 1;
    ll k = n - r;
    for (ll x = n; x > k; x--) {
        res = (res * x) % 2000000011;
    }

    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        
        if (n == 1) {
            cout << "1\n";
        } else {
            ll res = P(n, n) - P(n-1, n-1);
            cout << res << "\n";
        }
    }

    return 0;
}