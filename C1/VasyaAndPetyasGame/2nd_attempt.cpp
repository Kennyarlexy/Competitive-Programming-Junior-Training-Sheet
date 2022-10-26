#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool checked[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    ll lcm = 1;
    for (ll y = 2; y <= n; y++) {
        if (checked[y]) continue;
        cout << y << " ";
        checked[y] = true;
        if (n % y == 0) {
            lcm = lcm*y / __gcd(lcm, y);
            for (ll k = lcm; k <= n; k*=2) {
                if (checked[k]) continue;
                cout << k << " ";
                checked[k] = true;
                if (n % k != 0) break;
            }
            
            // while (true) {
            //     if (checked[k]) continue;
            //     cout << k << " ";
            //     checked[k] = true;
            //     if (n % k != 0) break;
            //     k += lcm;
            // }
        }
    }

    cout << "\n";

    return 0;
}