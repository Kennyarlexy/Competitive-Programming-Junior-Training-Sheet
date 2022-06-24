#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[1005];

int main() {
    fast_io();
    ll n, k, l, r, sall, sk;
    cin >> n >> k >> l >> r >> sall >> sk;

    ll a = r;
    while (n*(a-1) >= sall) a--;
    ll d = n*a - sall;

    fill(A, A + n - d, a);
    fill(A + n - d, A + n, a-1);

    ll tempsk = 0;
    for (ll i = 0; i < k; i++) {
        tempsk += A[i];
    }
    ll need = sk - tempsk;

    ll x = need;
    for (ll i = 0; i < k && x > 0; i++) {
        ll y = min(r - A[i], x);
        A[i] += y;
        x -= y;
    }

    ll p = need;
    for (ll i = n-1; i >= 0 && p > 0; i--) {
        ll q = min(A[i] - l, p);
        A[i] -= q;
        p -= q;
    }
    for (ll i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}