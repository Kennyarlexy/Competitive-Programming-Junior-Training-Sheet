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
    
    int max = ((n/2) * n) + ((n+1) / 2 * (n % 2));
    // cout << max << "\n";
    if (k > max) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if ((c + r) % 2 == 0 && k > 0) {
                    cout << "L";
                    k--;
                } else {
                    cout << "S";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}