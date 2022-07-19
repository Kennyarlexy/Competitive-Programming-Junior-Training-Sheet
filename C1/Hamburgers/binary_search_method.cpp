#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string recipe;
ll nb, ns, nc;
ll pb, ps, pc;
ll r;
ll cntB = 0, cntS = 0, cntC = 0;


ll f(ll x) { // money needed to make x burger
    ll bb = max(0LL, x * cntB - nb);
    ll bs = max(0LL, x * cntS - ns);
    ll bc = max(0LL, x * cntC - nc);

    ll M = bb*pb + bs*ps + bc*pc;
    return M;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    for (ll i = 0; i < recipe.length(); i++) {
        if (recipe[i] == 'B') cntB++;
        else if (recipe[i] == 'S') cntS++;
        else cntC++;
    }

    ll res = 0;
    for (ll step = 1000000000000LL; step >= 1; step/=2) {
        while (f(res + step) <= r) res += step;
    }

    cout << res << "\n";

    return 0;
}