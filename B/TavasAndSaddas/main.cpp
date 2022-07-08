#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<ll> lucky;

int main() {
    fast_io();
    //use ll when possible!
    for (ll digit = 1; digit <= 9; digit++) {
        for (ll i = 0; i < (1 << digit); i++) {
            ll temp = 0;
            for (ll j = 0; j < digit; j++) {
                if (i & (1 << j)) temp = temp*10 + 7;
                else temp = temp*10 + 4;
            }
            lucky.push_back(temp);
        }
    }

    sort(lucky.begin(), lucky.end());

    ll n; cin >> n;
    for (ll i = 0; i < lucky.size(); i++) {
        if (n == lucky[i]) {
            cout << i+1 << "\n";
            break;
        }
    }

    return 0;
}