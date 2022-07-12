#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll at[55];
bool PS(ll n) {
    ll temp = sqrt(n);
    if (temp*temp != n) return false;
    return true;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(at, 0, sizeof(at));
        ll N; cin >> N;
        ll empty = 1;
        ll k = 1;
        while (true) {
            bool OK = false;
            for (ll i = 1; i < empty; i++) {
                if (PS(at[i] + k)) {
                    at[i] = k;
                    OK = true;
                    break;
                }
            }
            if (!OK) {
                if (empty <= N) {
                    at[empty] = k;
                    empty++;
                } else {
                    break;
                }
            }
            k++;
        }
        cout << k - 1 << "\n";
    }


    return 0;
}