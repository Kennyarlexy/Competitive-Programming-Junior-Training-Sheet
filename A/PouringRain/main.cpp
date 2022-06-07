#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    double pi = 3.14159265359;
    int d, h, v, e;
    cin >> d >> h >> v >> e;

    double E = 4*v / (pi * d*d);
    double net = E - e;
    if (net < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        double t = h / net;
        cout << fixed << setprecision(10) << t << "\n";
    }


    return 0;
}