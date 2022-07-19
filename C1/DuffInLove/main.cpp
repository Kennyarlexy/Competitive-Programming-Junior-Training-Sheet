#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    set<ll> div;
    for (ll k = 2; k*k <= n; k++) {
        while (n % k == 0) {
            n /= k;
            div.insert(k);
        }
    }

    if (n > 1) div.insert(n);

    ll res = 1;
    for (auto& data : div) {
        res *= data;
    }

    cout << res << "\n";

    return 0;
}