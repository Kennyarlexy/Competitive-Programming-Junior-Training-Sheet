#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cntA[10];
ll cntB[10];

int main() {
    fast_io();
    //use ll when possible!
    ll a, b; cin >> a >> b;
    ll div[] = {2, 3, 5};
    for (auto& D : div) {
        while (a % D == 0) {
            a /= D;
            // cout << "dividing " << D << "A\n";
            cntA[D]++;
        }

        while (b % D == 0) {
            b /= D;
            // cout << "dividing " << D << "B\n";
            cntB[D]++;
        }
    }

    if (a != b) cout << "-1\n";
    else {
        ll res = abs(cntA[2] - cntB[2]) + abs(cntA[3] - cntB[3]) + abs(cntA[5] - cntB[5]);
        cout << res << "\n";
    }

    return 0;
}