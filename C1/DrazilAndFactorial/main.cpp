#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[15];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    string a; cin >> a;
    for (ll i = 0; i < n; i++) {
        if (a[i] == '4') {
            cnt[2] += 2;
            cnt[3] += 1;
        } else if (a[i] == '6') {
            cnt[3] += 1;
            cnt[5] += 1;
        } else if (a[i] == '8') {
            cnt[2] += 3;
            cnt[7] += 1;
        } else if (a[i] == '9') {
            cnt[2] += 1;
            cnt[3] += 2;
            cnt[7] += 1;
        } else if (a[i] > '1') {
            cnt[a[i] - '0']++;
        }
    }

    string res;
    for (ll i = 9; i >= 2; i--) {
        for (ll k = 1; k <= cnt[i]; k++) {
            res += i + '0';
        }
    }

    cout << res << "\n";

    return 0;
}