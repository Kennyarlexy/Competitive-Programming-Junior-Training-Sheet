#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll compute(ll base, ll exp, ll mod) {
    if (exp == 0) return 1 % mod;

    ll result = compute(base, exp / 2, mod);
    result = (result * result) % mod;
    if (exp % 2 == 1) result = (base * result) % mod;

    return result;
}

int main() {
    ll base, exp, mod;
    while (cin >> base >> exp >> mod) {
        ll result = compute(base, exp, mod);
        cout << result << "\n";
    }

    return 0;
}