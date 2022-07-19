#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll C[55];
vector<ll> LCM;

ll lcm(ll A[]) {
    ll res = 1;
    for (ll i = 0; i < 4; i++) {
        res = res * A[i] / __gcd(res, A[i]);
    }
    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll n, t;
    while (true) {
        cin >> n >> t;
        if (n == 0 && t == 0) break;

        LCM = vector<ll> ();
        for (ll i = 0; i < n; i++) {
            cin >> C[i];
        }

        for (ll i1 = 0; i1 < n; i1++) {
            for (ll i2 = i1 + 1; i2 < n; i2++) {
                for (ll i3 = i2 + 1; i3 < n; i3++) {
                    for (ll i4 = i3 + 1; i4 < n; i4++) {
                        ll A[] = {C[i1], C[i2], C[i3], C[i4]};
                        LCM.push_back(lcm(A));
                    }
                }
            }
        }

        for (ll i = 0; i < t; i++) {
            ll h; cin >> h;
            ll low = 0, high = LONG_LONG_MAX;
            for (ll j = 0; j < LCM.size(); j++) {
                if (h % LCM[j] == 0) {
                    low = high = h;
                    break;
                }
                
                ll seg = h / LCM[j];
                ll tlow = LCM[j] * seg;
                ll thigh = LCM[j] * (seg + 1);
                if (tlow < h && tlow > low) low = tlow;
                if (thigh > h && thigh < high) high = thigh;
            }
            cout << low << " " << high << "\n";
        }
    }

    return 0;
}