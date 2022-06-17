#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll H[50005];

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int h; cin >> h;
        int resL = -1;
        if (h > H[1]) {
            int k = 1;
            for (int step = n/2; step >= 1; step/=2) {
                while (k+step <= n && H[k+step] < h) {
                    k += step;
                }
            }
            resL = H[k];
        }
        if (resL != -1) cout << resL << " ";
        else cout << "X ";

        int resH = -1;
        if (h < H[n]) {
            int k = n;
            for (int step = n/2; step >= 1; step/=2) {
                while (k-step >= 1 && H[k-step] > h) {
                    k -= step;
                }
            }
            resH = H[k];
        }
        if (resH != -1) cout << resH << "\n";
        else cout << "X\n";
    }

    return 0;
}