#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int p, q, l, r; cin >> p >> q >> l >> r;
    pair<int, int> Z[p];
    pair<int, int> X[q];
    for (int i = 0; i < p; i++) {
        cin >> Z[i].first >> Z[i].second;
    }

    for (int i = 0; i < q; i++) {
        cin >> X[i].first >> X[i].second;
    }

    int result = 0;
    for (int t = l; t <= r; t++) {
        bool OK = false;
        for (auto& u : Z) {
            int a, b;
            tie(a, b) = u;
            for (auto& v : X) {
                int c, d;
                tie(c, d) = v;
                if ((c + t >= a && c + t <= b) || (d + t >= a && d + t <= b)) {
                    OK = true;
                    goto done;
                }
            }
        }
        done:
        if (OK) result++;
    }
    cout << result << "\n";

    return 0;
}