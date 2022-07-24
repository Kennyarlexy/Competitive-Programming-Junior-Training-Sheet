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
    while (true) {
        ll N; cin >> N;
        if (N == 0) break;

        ll a, b; cin >> a >> b;
        map<ll, ll> M;

        ll prev = 0;
        ll step = 0;
        M.emplace(0, 0);
        while (true) {
            ll next = ((a*prev) % N * prev + b) % N;
            map<ll, ll>::iterator it;
            bool in;
            tie(it, in) = M.emplace(next, ++step);
            
            if (!in) {
                ll res = N - (M[prev] - it->second + 1);
                cout << res << "\n";
                break;
            }

            prev = next;
        }
    }

    return 0;
}