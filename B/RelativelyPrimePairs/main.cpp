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
    ll l, r; cin >> l >> r;
    cout << "YES\n";
    for (ll i = l; i <= r - 1; i+=2) {
        cout << i << " " << i+1 << "\n";
    }

    return 0;
}