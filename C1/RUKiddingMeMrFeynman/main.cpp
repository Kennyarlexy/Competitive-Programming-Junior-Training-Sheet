#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    double n; 
    while (cin >> n) {
        if (n == 0) break;
        ll ta = cbrt(n);
        double a = ta;
        double dx = (n - a*a*a) / (3*a*a);
        double res = a + dx;
        cout << fixed << setprecision(4) << res << "\n";
    }

    return 0;
}