#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int A[105];

int main() {
    fast_io();
    int n; cin >> n;
    bool hasNut = false;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] == 1) hasNut = true;
    }

    int pone = -1;

    ll res = hasNut;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            if (pone != -1) res *= (i - pone);
            pone = i;
        }
    }
    cout << res << "\n";
    // vector<int> pone;
    // for (int i = 0; i < n; i++) {
    //     cin >> A[i];
    //     if (A[i] == 1) pone.push_back(i);
    // }

    // ll cnt = (pone.size() > 0);

    // for (int i = 1; i < pone.size(); i++) {
    //     ll temp = 0;
    //     for (int j = i; j < pone.size(); j++) {
    //         if (A[j] == 0) temp++;
    //     }

    //     temp *= (pone[i] - pone[i-1]);
    //     cnt += temp;
    // }
    // cout << cnt << "\n";

    return 0;
}