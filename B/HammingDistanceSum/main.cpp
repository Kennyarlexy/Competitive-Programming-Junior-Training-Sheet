#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll pre1[200005];
ll pre0[200005];

int main() {
    fast_io();
    //use ll when possible!
    string S, L; cin >> S >> L;
    ll lenL = L.length();

    ll temp0 = 0, temp1 = 0;
    for (ll i = 0; i < lenL; i++) {
        if (L[i] == '1') temp1++;
        else temp0++;
        pre0[i] = temp0;
        pre1[i] = temp1;
    }

    ll lenS = S.length();
    ll res = 0;
    for (ll iS = 0; iS < lenS; iS++) {
        if (S[iS] == '0') {
            res += pre1[lenL - lenS + iS]; 
            if (iS > 0) res -= pre1[iS-1];
        } else {
            res += pre0[lenL - lenS + iS]; 
            if (iS > 0) res -= pre0[iS-1];
        }
    }
    cout << res << "\n";

    return 0;
}