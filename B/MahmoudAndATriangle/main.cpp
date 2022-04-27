#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    ll n; cin >> n;
    int side[n];
    for (ll i = 0; i < n; i++) {
        cin >> side[i];
    }
    sort(side, side + n, greater<int>());
    for (ll i = 0; i < n - 2; i++) {
        if (side[i+1] + side[i+2] > side[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}