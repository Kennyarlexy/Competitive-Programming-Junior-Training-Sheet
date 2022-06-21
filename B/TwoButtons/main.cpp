#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    int moves = 0;
    while (m > n) {
        if (m % 2 == 1) moves++;
        m = (m+1) / 2;
        moves++;
    }
    moves += (n - m);
    cout << moves << "\n";

    return 0;
}