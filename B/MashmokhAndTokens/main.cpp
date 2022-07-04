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
    ll n, a, b; cin >> n >> a >> b;
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        ll rem = ((x*a) % b) / a;
        cout << rem;
        if (i < n) cout << " ";
    }
    cout << "\n";

    return 0;
}