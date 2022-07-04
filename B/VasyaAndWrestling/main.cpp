#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll F[200005];
ll S[200005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    ll iS = 0, iF = 0;
    ll cntF = 0, cntS = 0;
    ll totF = 0, totS = 0;
    ll last = 0;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        if (a < 0) {
            totS -= a;
            S[++iS] = -a;
            cntS++;
            last = 2;
        } else {
            totF += a;
            F[++iF] = a;
            cntF++;
            last = 1;
        }
    }

    if (totF > totS) {
        cout << "first\n";
    } else if (totF < totS) {
        cout << "second\n";
    } else {
        bool OK = false;
        for (ll i = 1; i <= min(iF, iS); i++) {
            if (F[i] > S[i]) {
                cout << "first\n";
                OK = true;
                break;
            } else if (S[i] > F[i]) {
                cout << "second\n";
                OK = true;
                break;
            }
        }
        if (!OK) {
            cout << (last == 1 ? "first" : "second") << "\n";
        }
    }


    return 0;
}