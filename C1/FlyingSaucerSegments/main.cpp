#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll modexp(ll n, ll exp, ll mod) {
    if (exp == 0) return 1;

    ll root = modexp(n, exp/2, mod);
    ll res = (root*root) % mod;
    if (exp % 2 == 1) res = (res*n) % mod;
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n, m; cin >> n >> m;
    ll res = (m + modexp(3, n, m) - 1) % m;
    cout << res << "\n";

    return 0;
}