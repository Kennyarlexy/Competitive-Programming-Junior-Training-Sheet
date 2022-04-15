#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    pair<ll, ll> box[m];
    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        box[i] = make_pair(b, a);
    }
    sort(box, box + m, greater<pair<ll, ll>>());

    ll count = 0;
    for (ll i = 0; i < m; i++) {
        ll take = fmin(box[i].second, n);
        ll takematch = take * box[i].first;
        count += takematch;
        n -= take;
        if (n == 0) break;
    }
    cout << count << "\n";

    return 0;
}