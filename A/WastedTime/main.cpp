#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, k; cin >> n >> k;
    int px, py;
    long double totalR = 0;
    for (int i = 1; i <= n; i++) {
        int cx, cy; cin >> cx >> cy;
        if (i > 1) {
            long double R = sqrt(pow(abs(cx-px), 2) + pow(abs(cy-py), 2));
            totalR += R;
        }
        px = cx;
        py = cy;
    }

    long double time = totalR / 50 * k;
    cout << fixed << setprecision(10) << time << "\n";

    return 0;
}