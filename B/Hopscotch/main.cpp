#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    ll a, x, y; cin >> a >> x >> y;
    if (y % a == 0 || y < 0) {
        cout << "-1\n";
    } else {
        ll r = (y+a-1) / a;

        if (r == 1) {
            if (x > (double) -a / 2 && x < (double) a / 2) {
                cout << "1\n";
            } else {
                cout << "-1\n";
            }
        } else if (r % 2 == 0) {
            if (x > (double) -a / 2 && x < (double) a / 2) {
                ll k = 2 + (r-2) / 2 * 3;
                cout << k << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            if (x < 0 && x > -a) {
                ll k = 3 + (r-3) / 2 * 3;
                cout << k << "\n";
            } else if (x > 0 && x < a) {
                ll k = 4 + (r-3) / 2 * 3;
                cout << k << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}