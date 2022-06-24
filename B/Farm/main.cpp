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
    ll n; cin >> n;
    if (n == 1) {
        cout << "1 2 3\n";
    } else if (n == 2) {
        cout << "3 4 5\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}