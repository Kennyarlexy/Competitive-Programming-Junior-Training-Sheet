#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll B[100005];
bool checked[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> B[i];
    }

    ll res = 0;
    ll iB = 0;
    for (ll iA = 0; iA < n; iA++) {
        if (checked[A[iA]]) continue;
        while (A[iA] != B[iB]) {
            res++;
            checked[B[iB]] = true;
            iB++;
        }
        iB++;
    }

    cout << res << "\n";

    return 0;
}