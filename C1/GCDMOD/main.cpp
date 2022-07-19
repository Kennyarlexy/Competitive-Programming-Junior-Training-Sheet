#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll modexp(ll X, ll exp, ll mod) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = temp * temp; //sadly at this line it can overflow
    if (exp % 2 == 1) res *= X;
    return res % mod; //since previously called modexp can return up to 1e12 - 1
}


int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll A, B, N; cin >> A >> B >> N;
        ll diff = A - B;
        ll res;
        if (diff == 0) {
            res = (modexp(A, N, 1000000007) + modexp(B, N, 1000000007)) % 1000000007;
        } else {
            res = __gcd(diff, (modexp(A, N, diff) + modexp(B, N, diff)) % diff) % 1000000007;
        }
        cout << res << "\n";
    }

    return 0;
}