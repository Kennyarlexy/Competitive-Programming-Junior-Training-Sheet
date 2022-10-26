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
    ll x = 2;
    while (true) {
        cout << x << " ";
        if (n % x == 0) {
            x *= 2;
        } else {
            for (ll y = x+1; y < 2*x; y++) {
                cout << y << " ";
                if (n % y == 0) {
                    x = x*y / __gcd(x, y);
                    break;
                }
            }
        }
    }

    return 0;
}