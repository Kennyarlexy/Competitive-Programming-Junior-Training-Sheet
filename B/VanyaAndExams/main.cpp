#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<ll, ll> E[100005];

bool cmp(pair<ll, ll> A, pair<ll, ll> B) {
    return (A.second < B.second);
}

int main() {
    fast_io();
    //use ll when possible!
    ll n, r, avg; cin >> n >> r >> avg;
    ll total = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> E[i].first >> E[i].second;
        total += E[i].first;
    }

    ll pneed = avg*n - total;
    sort(E + 1, E + n + 1, cmp);

    ll res = 0;
    for (ll i = 1; i <= n && pneed > 0; i++) {
        if (E[i].first >= r) continue;
        res += min(pneed, r - E[i].first) * E[i].second;
        pneed -= min(pneed, r - E[i].first);
    }

    cout << res << "\n";

    return 0;
}