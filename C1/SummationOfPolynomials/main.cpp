#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll F(ll x, ll deg) {
    if (x == 0) return 1;
    ll res = 1;
    for (ll k = x; k > x - deg; k--) {
        res *= k;
    }
    
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll x;
    while (cin >> x) {
        ll res = (F(x + 1, 4) + 4 * F(x + 1, 3) + 2 * F(x + 1, 2)) / 4;
        cout << res << "\n";
    }

    return 0;
}