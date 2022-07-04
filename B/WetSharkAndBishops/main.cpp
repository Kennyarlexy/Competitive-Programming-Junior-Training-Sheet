#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll d1[2005];
ll d2[2005];

ll findComb(ll cnt) {
    if (cnt <= 1) return 0;
    ll temp = 1;
    ll k = cnt - 2;
    bool OK = false;
    for (ll n = cnt; n >= k+1; n--) {
        temp *= n;
        if (!OK && temp % 2 == 0) {
            temp /= 2;
            OK = true;
        }
    }
    return temp;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll r, c; cin >> r >> c;
        ll id1 = r - c + 999;
        ll id2 = r + c - 2;
        d1[id1]++;
        d2[id2]++;
    }

    ll res = 0;
    for (ll i = 0; i < 2000; i++) {
        res += findComb(d1[i]);
        res += findComb(d2[i]);
    }
    cout << res << "\n";

    return 0;
}