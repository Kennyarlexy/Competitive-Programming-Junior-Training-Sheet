#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int T; cin >> T;
    int R1[5], R2[5];
    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= 4; i++) {
            cin >> R1[i];
        }
        for (int i = 1; i <= 4; i++) {
            cin >> R2[i];
        }

        int sx[] = {R1[1], R1[3], R2[1], R2[3]};
        int sy[] = {R1[2], R1[4], R2[2], R2[4]};
        sort(sx, sx + 4);
        sort(sy, sy + 4);

        int totW = (R1[3] - R1[1]) + (R2[3] - R2[1]);
        int totH = (R1[4] - R1[2]) + (R2[4] - R2[2]);

        if (sx[3] - sx[0] >= totW || sy[3] - sy[0] >= totH) {
            cout << "No Overlap\n";
        } else {
            cout << sx[1] << " " << sy[1] << " " << sx[2] << " " << sy[2] << "\n";
        }

        if (t < T) cout << "\n";
    }

    return 0;
}