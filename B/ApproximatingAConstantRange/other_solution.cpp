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
    cnt[A[li]]++;
    cnt[A[ri]]++;
    ll M = A[li];
    ll m = A[ri];
    if (M < m) swap(M, m);

    while (ri < n - 1) {
        if (cnt[M] + cnt[m] < ri - li + 1) {
            cnt[A[li]]--;
            li++;
        } else {
            ri++;
            cnt[A[ri]]++;
        }
        
        if (max(A[li], A[ri]) > M) {
            m = M;
            M = max(A[li], A[ri]);
        } else if (min(A[li], A[ri]) < m) {
            M = m;
            m = min(A[li], A[ri]);
        }

        if (cnt[M] + cnt[m] >= ri - li + 1) {
            len = max(len, ri - li + 1);
        }
    }
    cout << len << "\n";

    return 0;
}