#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll cnt[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll li = 0;
    ll ri = 1;

    ll len = 2;
    set<ll> distinct;
    distinct.insert(A[li]);
    distinct.insert(A[ri]);
    cnt[A[li]]++;
    cnt[A[ri]]++;

    while (ri < n - 1) {
        if (distinct.size() <= 2) {
            ri++;
            distinct.insert(A[ri]);
            cnt[A[ri]]++;
        } else {
            cnt[A[li]]--;
            if (cnt[A[li]] == 0) distinct.erase(A[li]);
            li++;
        }
        if (distinct.size() <= 2) len = max(len, ri - li + 1);
    }
    cout << len << "\n";

    return 0;
}