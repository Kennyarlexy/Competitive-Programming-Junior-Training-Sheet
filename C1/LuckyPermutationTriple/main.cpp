#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll B[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
    } else {
        ll i = 1;
        for (ll x = 0; x < n; x++) {
            ll Ai = i % n;
            A[Ai] = (x + 1) % n;
            B[Ai] = x;
            i += 2;
        }

        for (ll j = 0; j < n; j++) {
            cout << A[j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";

        for (ll j = 0; j < n; j++) {
            cout << B[j];
            if (j < n - 1) cout << " ";

        }
        cout << "\n";

        for (ll j = 0; j < n; j++) {
            cout << j;
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}