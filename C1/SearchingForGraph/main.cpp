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
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, p; cin >> n >> p;
        ll target = 2*n + p;
        ll usable = target - (n - 1);
        ll used = 0;
        for (ll u = 2; u <= n; u++) {
            ll limit = 2*u + p;
            usable++;
            for (ll v = 1; v <= u-1; v++) {
                if (used == limit || used == usable) break;
                cout << u << " " << v << "\n";
                used++;
            }
        }
        // cout << used << "\n";
    }

    return 0;
}