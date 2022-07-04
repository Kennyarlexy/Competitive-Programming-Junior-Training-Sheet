#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll grid[105][105];
ll cnt1_inr[105];
ll cnt1_inc[105];

bool has1_r[105];
bool has1_c[105];

ll res[105][105];

int main() {
    fast_io();
    //use ll when possible!
    ll m, n; cin >> m >> n;
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                cnt1_inr[i]++;
                cnt1_inc[j]++;
            }
        }
    }

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (cnt1_inr[i] == n && cnt1_inc[j] == m) {
                res[i][j] = 1;
                has1_r[i] = true;
                has1_c[j] = true;
            }
        }
    }

    bool valid = true;
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (grid[i][j] == 1) {
                if (!has1_r[i] && !has1_c[j]) {
                    valid = false;
                    break;
                }
            }
        }
    }

    if (valid) {
        cout << "YES\n";
        for (ll i = 1; i <= m; i++) {
            for (ll j = 1; j <= n; j++) {
                cout << res[i][j];
                if (j < n) cout << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }

    // cout << "res:\n";
    // for (ll i = 1; i <= m; i++) {
    //     for (ll j = 1; j <= n; j++) {
    //         cout << res[i][j];
    //         if (j < n) cout << " ";
    //     }
    //     cout << "\n";
    // }

    // for (ll i = 1; i <= m; i++) {
    //     cout << "cnt1_inr " << i << " = " << cnt1_inr[i] << "\n";
    // }
    // for (ll j = 1; j <= n; j++) {
    //     cout << "cnt1_inc " << j << " = " << cnt1_inc[j] << "\n";
    // }

    return 0;
}