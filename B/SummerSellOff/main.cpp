#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Sales {
    int stock;
    int customer;
    int diff;
};

bool cmp(Sales a, Sales b) {
    return (a.diff > b.diff);
}

int main() {
    fast_io();
    int n, f; cin >> n >> f;
    Sales arr[n];
    for (int i = 0; i < n; i++) {
        int k, l; cin >> k >> l;
        arr[i].stock = k;
        arr[i].customer = l;
        arr[i].diff = fmin(2*k, l) - fmin(k, l);
    }
    sort(arr, arr + n, cmp);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        if (i < f) {
            total += fmin(2*arr[i].stock, arr[i].customer);
        } else {
            total += fmin(arr[i].stock, arr[i].customer);
        }
    }
    cout << total << "\n";

    return 0;
}