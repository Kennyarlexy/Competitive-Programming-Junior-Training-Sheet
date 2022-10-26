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
    ll p, d; cin >> p >> d;
    ll trim = 1;
    while (p / trim >= 10) {
        ll digit = (p / trim) % 10;
        ll x = (digit + 1) % 10 * trim;
        if (x > d) break;
        p -= x;
        d -= x;
        trim *= 10;
    }
    cout << p << "\n";

    return 0;
}