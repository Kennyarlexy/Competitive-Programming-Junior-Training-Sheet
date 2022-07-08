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
    string a; ll k;
    cin >> a >> k;
    for (ll iIns = 0; iIns < a.length() - 1 && k > 0; iIns++) {
        char max = a[iIns];
        ll imax = -1;
        for (ll iSrc = iIns + 1; iSrc < a.length() && iSrc <= k + iIns; iSrc++) {
            if (a[iSrc] > max) {
                max = a[iSrc];
                imax = iSrc;
            }
        }
        // cout << iIns << " " << imax << "\n";
        if (imax != -1) {
            // cout << "erasing " << a[imax] << "\n";
            a.erase(imax, 1);
            a.insert(iIns, to_string(max - '0'));
            k -= (imax - iIns);
        }
    }

    cout << a << "\n";

    return 0;
}