#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> A[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll n, d; cin >> n >> d;
    for (ll i = 0; i < n; i++) {
        ll m, f; cin >> m >> f;
        A[i] = {m, f};
    }

    sort(A, A + n);
    ll res = 0;
    ll iL = 0;
    ll iR = 0;

    ll temp = 0;
    while (iR < n) {
        if (A[iR].first - A[iL].first < d) {
            temp += A[iR].second;
            iR++;
        } else {
            for (ll i = iL; i <= iR; i++) {
                if (A[iR].first - A[i].first < d) {
                    iL = i;
                    break;
                }
                temp -= A[i].second;
            }
        }
        res = max(res, temp);
    }
    cout << res << "\n";

    return 0;
}