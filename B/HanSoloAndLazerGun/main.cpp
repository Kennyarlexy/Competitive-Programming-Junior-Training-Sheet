#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    set<double> m;
    
    bool hasV = false;
    for (int i = 1; i <= n; i++) {
        double x, y; cin >> x >> y;
        if (x == x0) hasV = true;
        else {
            double gradient = (y - y0) / (x - x0);
            m.insert(gradient);
        }
    }

    int res = m.size() + hasV;
    cout << res << "\n";

    return 0;
}