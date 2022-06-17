#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    string s; cin >> s;
    int len = s.length();
    int previb = -1;
    ll res = 0;
    for (int i = 0; i < len - 3; i++) {
        if (s.substr(i, 4) == "bear") {
            int ib = i, ir = i + 3;
            int nl = ib + 1 - (previb + 1);
            int nr = len - 1 - ir + 1;
            res += nl * nr;
            previb = ib;
        }
    }
    cout << res << "\n";

    return 0;
}