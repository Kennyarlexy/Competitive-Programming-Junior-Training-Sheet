#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll h[150005];
ll sum[150005];

int main() {
    fast_io();
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    ll temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += h[i];
        sum[i] = temp;
    }

    sum[0] = 0;
    ll pos = 0;
    ll min = LONG_LONG_MAX;
    for (int i = 1; i <= n-k+1; i++) {
        ll current = sum[i+k-1] - sum[i-1];
        if (current < min) {
            min = current;
            pos = i;
        }
    }
    cout << pos << "\n";

    return 0;
}