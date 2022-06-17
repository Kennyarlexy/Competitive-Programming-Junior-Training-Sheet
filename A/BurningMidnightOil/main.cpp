#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll sum(int v, int k) {
    ll sum = 0;
    while (v > 0) {
        sum += v;
        v/=k;
    }
    return sum;
}

int main() {
    fast_io();
    int n, k; cin >> n >> k;

    int v = 1e9;
    for (int step = 1e9/2; step >= 1; step/=2) {
        while (sum(v-step, k) >= n) v -= step;
    }

    cout << v << "\n";

    return 0;
}