#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int A[100005];

int main() {
    fast_io();
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll res = 0;

    int i = 1;
    for (i; i <= n - 1; i++) {
        if (k > 0) {
            if (A[i] < 0) {
                if (-A[i] < A[i+1]) break;
                res += -A[i];
                k--;
            } else {
                res += (k % 2 == 0 ? A[i] : -A[i]);
                k = 0;
            } 
        } else {
            res += A[i];
        }
    }
    res += (k % 2 == 0 ? A[i] : -A[i]);

    for (i = i + 1; i <= n; i++) {
        res += A[i];
    }
    cout << res << "\n";

    return 0;
}