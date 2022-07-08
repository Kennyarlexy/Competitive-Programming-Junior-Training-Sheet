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
    ll totA = 0, totG = 0;
    string res;
    for (ll i = 0; i < n; i++) {
        ll a, g; cin >> a >> g;
        if (abs((totA + a) - totG) < abs(totA - (totG + g))) {
            res += 'A';
            totA += a;
        } else {
            res += 'G';
            totG += g;
        }
    }
    if (abs(totA - totG) > 500) {
        cout << "-1\n"; //always possible?
    } else {
        cout << res << "\n";
    }

    return 0;
}