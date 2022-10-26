#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Operation {
    ll l, r, d;
};

ll A[100005];
Operation O[100005];
ll D[100005];
ll cnt[100005];


int main() {
    fast_io();
    //use ll when possible!
    ll n, m, k; cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (ll i = 1; i <= m; i++) {
        cin >> O[i].l >> O[i].r >> O[i].d;
    }

    for (ll i = 1; i <= k; i++) {
        ll x, y; cin >> x >> y;
        cnt[x]++;
        cnt[y+1]--;
    }

    for (ll i = 1; i <= m; i++) {
        cnt[i] += cnt[i-1];
    }

    for (ll i = 1; i <= m; i++) {
        D[O[i].l] += O[i].d * cnt[i];
        D[O[i].r + 1] -= O[i].d * cnt[i];
    }

    for (ll i = 1; i <= n; i++) {
        D[i] += D[i-1];
        A[i] += D[i];
    }

    for (ll i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    
    return 0;
}