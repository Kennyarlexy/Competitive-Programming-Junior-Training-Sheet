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
    ll n, d; cin >> n >> d;
    ll m; cin >> m;
    for (ll i = 1; i <= m; i++) {
        ll xi, yi; cin >> xi >> yi;
        ll yt, yl;
        if (xi >= 0 && xi <= n - d) {
            yt = xi + d;
        } else if (xi >= n - d && xi <= n) {
            yt = -xi + 2*n - d;
        }

        if (xi >= 0 && xi <= d) {
            yl = -xi + d;
        } else if (xi >= d && xi <= n) {
            yl = xi - d;
        }

        if (yi >= yl && yi <= yt) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}