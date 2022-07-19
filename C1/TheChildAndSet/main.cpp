#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll lowbit(ll x) {
    for (ll i = 0; i < 64; i++) {
        if (x & (1 << i)) {
            return (1LL << i);
        }
    }

    return 0;
}

int main() {
    fast_io();
    // use ll when possible!
    ll sum, limit; cin >> sum >> limit;
    vector<ll> res;
    for (ll x = limit; x >= 1 && sum > 0; x--) {
        ll k = lowbit(x);
        if (k > sum) continue;
        res.push_back(x);
        sum -= k;
    }

    if (sum == 0) {
        cout << res.size() << "\n";
        for (ll i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";

        // ll total = 0;
        // for (ll i = 0; i < res.size(); i++) {
        //     cout << lowbit(res[i]) << " "; 
        //     total += lowbit(res[i]);
        // }

        // cout << "\n";
        // cout << total << "\n";
    } else {
        cout << "-1\n";
    }
    
    return 0;
}