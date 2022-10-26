#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll sum[100005];

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N, K; cin >> N >> K;
        string s; cin >> s;
        ll temp = 0;
        for (ll i = 0; i < N; i++) {
            if (s[i] == '1') temp++;
            sum[i] = temp;
        }

        ll A = 0;
        for (ll i = 0; i < N; i++) {
            if (s[i] == '1') {
                ll l = i;
                ll r = min(N - 1, i + K);
                A += (sum[r] - sum[l]) * 2 + 1;
            }
        }

        ll B = N*N;
        ll gcd = __gcd(A, B);
        A /= gcd;
        B /= gcd;
        cout << A << "/" << B << "\n";
    }

    return 0;
}