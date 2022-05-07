#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, l; cin >> n >> l;
    int pos[n+2];
    pos[0] = 0;
    pos[n+1] = l;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + n + 2);

    double max = 0;
    for (int i = 0; i < n + 2; i++) {
        if (i == 1 || i == n + 1) {
            double r = pos[i] - pos[i-1];
            max = fmax(max, r);
        } else {
            double r = (pos[i] - pos[i-1]) / 2.0;
            max = fmax(max, r);
        }
    }
    cout << fixed << setprecision(10) << max << "\n";

    return 0;
}