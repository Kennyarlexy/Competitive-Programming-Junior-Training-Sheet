#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int R[1005];
int xr[1005];
int yr[1005];

int main() {
    fast_io();
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> xr[i] >> yr[i] >> R[i];
    }

    int cnt = 0;

    for (int gx = xa; gx <= xb; gx++) {
        bool OK1 = false;
        bool OK2 = false;
        for (int i = 1; i <= n; i++) {
            int dx = xr[i] - gx;
            int dy1 = yr[i] - ya;
            int dy2 = yr[i] - yb;

            if (dx*dx + dy1*dy1 <= R[i]*R[i]) {
                OK1 = true;
            }

            if (dx*dx + dy2*dy2 <= R[i]*R[i]) {
                OK2 = true;
            }
        }

        cnt += !OK1 + !OK2;
    }

    for (int gy = ya + 1; gy < yb; gy++) {
        bool OK1 = false;
        bool OK2 = false;
        for (int i = 1; i <= n; i++) {
            int dx1 = xr[i] - xa;
            int dx2 = xr[i] - xb;
            int dy = yr[i] - gy;

            if (dx1*dx1 + dy*dy <= R[i]*R[i]) {
                OK1 = true;
            }

            if (dx2*dx2 + dy*dy <= R[i]*R[i]) {
                OK2 = true;
            }
        }
        cnt += !OK1 + !OK2;
    }
    cout << cnt << "\n";

    return 0;
}