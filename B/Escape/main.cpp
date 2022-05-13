#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    double tp = c/vp;
    int count = 0;
    while (true) {
        double T = vd*t / (vd-vp);
        if (T >= tp || T < 0) break;
        count++;
        t = 2*T - t + f;
    }
    cout << count << "\n";

    return 0;
}