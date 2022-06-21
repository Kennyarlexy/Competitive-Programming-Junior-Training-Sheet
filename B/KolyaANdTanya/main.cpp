#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll mod = 1e9 + 7;

int main() {
    fast_io();
    int n; cin >> n;
    ll A = 1;
    for (int i = 1; i <= n; i++) {
        A *= 27;
        A %= mod;
    }

    ll B = 1;
    for (int i = 1; i <= n; i++) {
        B *= 7;
        B %= mod;
    }

    ll res = (mod + (A - B)) % mod;

    cout << res << "\n";

    return 0;
}