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
    string s; cin >> s;
    ll m; cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    sort(A, A + m);
    ll len = s.length();
    bool prev = false;
    for (ll i = 0; i < m - 1; i++) {
        bool cur = (cnt[A[i]] + prev) % 2 == 1;
        if (cur) {
            for (ll j = A[i]; j < A[i+1]; j++) {
                swap(s[j - 1], s[len-j]);
            }
        }

        prev = cur;
    }

    if ((prev + cnt[A[m-1]]) % 2 == 1) {
        reverse(s.begin() + A[m-1] - 1, s.end() - A[m-1] + 1);
    }
    cout << s << "\n";

    return 0;
}