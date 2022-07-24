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
    unsigned ll a, b;
    while (cin >> a >> b) {
        unsigned ll res = a ^ b;
        cout << res << "\n";
    }

    return 0;
}