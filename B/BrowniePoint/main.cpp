#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int mid = ((n+1) / 2) - 1;
        int px[n];
        int py[n];
        int cx, cy;
        for (int i = 0; i < n; i++) {
            cin >> px[i] >> py[i];
            if (i == mid) {
                cx = px[i];
                cy = py[i];
            }
        }

        int S = 0, O = 0;
        for (int i = 0; i < n; i++) {
            if (px[i] == cx || py[i] == cy) continue;
            double m = (double) (py[i]-cy) / (px[i]-cx);
            if (m > 0) S++;
            else O++;
        }
        cout << S << " " << O << "\n";
    }

    return 0;
}