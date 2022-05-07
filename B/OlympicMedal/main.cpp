#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n; cin >> n;
    double maxr1 = 0;
    for (int i = 0; i < n; i++) {
        double r1; cin >> r1;
        maxr1 = fmax(maxr1, r1);
    }

    int m; cin >> m;
    double maxp1 = 0;
    for (int i = 0; i < m; i++) {
        double p1; cin >> p1;
        maxp1 = fmax(maxp1, p1);
    }

    int k; cin >> k;
    double minp2 = 10000;
    for (int i = 0; i < k; i++) {
        double p2; cin >> p2;
        minp2 = fmin(minp2, p2);
    }

    double A, B; cin >> A >> B;
    double r2 = sqrt((maxp1*B*maxr1*maxr1) / (minp2*A + maxp1*B));
    cout << fixed << setprecision(8) << r2 << "\n";

    return 0;
}