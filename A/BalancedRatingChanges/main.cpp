#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int C[15000];

int main() {
    fast_io();
    int n; cin >> n;
    ll sumE = 0;
    ll sumO = 0;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        if (C[i] % 2 == 0) sumE += C[i];
        else sumO += (C[i] / 2);
    }
    sumE /= 2;

    ll diff = sumE + sumO;
    // cout << diff << "\n";
    for (int i = 1; i <= n; i++) {
        if (C[i] % 2 == 0) cout << C[i] / 2 << "\n";
        else {
            int res = C[i] / 2;
            if (diff > 0 && C[i] < 0) {
                res--;
                diff--;
            } else if (diff < 0 && C[i] > 0) {
                res++;
                diff++;
            }
            cout << res << "\n";
        }
    }

    return 0;
}