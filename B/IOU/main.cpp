#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll diff[105];

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        diff[a] -= c;
        diff[b] += c;
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (diff[i] > 0) res += diff[i];
    }

    cout << res << "\n";

    return 0;
}