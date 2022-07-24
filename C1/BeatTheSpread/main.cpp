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
        double s, d; cin >> s >> d;
        double b = (s - d) / 2;
        if (b < 0 || (ll) b != b) {
            cout << "impossible\n";
        } else {
            ll a = s - b;
            cout << a << " " << (ll) b << "\n";
        }
    }

    return 0;
}