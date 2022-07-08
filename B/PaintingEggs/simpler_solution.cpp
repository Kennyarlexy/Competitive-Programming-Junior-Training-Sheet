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
    ll diff = 0;
    string res;
    for (ll i = 0; i < n; i++) {
        ll a, g; cin >> a >> g;
        if (diff + a < 500) {
            diff += a;
            res += 'A';
        } else {
            diff -= g;
            res += 'G';
        }
    }
    cout << res << "\n";

    return 0;
}