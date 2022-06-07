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
    for (int t = 1; t <= T; t++) {
        int a; cin >> a;
        double sides = 360.0 / (180 - a);
        int test = sides;
        if (sides == test) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}