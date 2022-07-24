#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll modexp(ll X, ll exp, ll mod = 2000000011) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = (temp * temp) % mod;
    if (exp % 2 == 1) res = (res * X) % mod;
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n; cin >> n;
        ll res;
        if (n == 1) {
            res = 1;
        } else {
            res = modexp(n, n-2);
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
    
    return 0;
}