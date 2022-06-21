#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll d(ll n) {
    ll f = 1;
    for (ll x = 2; x*x <= n; x++) {
        ll temp = 1;
        while (n % x == 0) {
            temp++;
            n /= x;
        }
        f *= temp;
        f %= 1073741824;
    }

    if (n > 1) f *= 2;

    return f % 1073741824;
}

int main() {
    fast_io();
    int i, j, k;
    cin >> i >> j >> k;
    ll res = 0;
    for (int a = 1; a <= i; a++) {
        for (int b = 1; b <= j; b++) {
            for (int c = 1; c <= k; c++) {
                res += d(a*b*c);
            }
        }
    }
    cout << res % 1073741824 << "\n";

    return 0;
}