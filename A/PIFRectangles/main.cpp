#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

double R[15][4];

int main() {
    fast_io();
    int n = 1;
    while (true) {
        char ch; cin >> ch;
        if (ch == '*') break;
        for (int j = 0; j < 4; j++) {
            cin >> R[n][j];
        }
        n += ch == 'r';
    }

    double x, y;
    int k = 0;
    while (true) {
        cin >> x >> y;
        if (x == 9999.9 && y == 9999.9) break;
        k++;
        bool OK = false;
        for (int i = 1; i <= n; i++) {
            if (x > R[i][0] && x < R[i][2] && y > R[i][3] && y < R[i][1]) {
                OK = true;
                cout << "Point " << k << " is contained in figure " << i << "\n";
            }
        }

        if (!OK) {
            cout << "Point " << k << " is not contained in any figure\n";
        }
    }

    return 0;
}