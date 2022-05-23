#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll D[5];

ll f(ll end) {
    ll subset = (1 << 5); //actually subset + 1
    //index of this binary that is true means that index of D is used

    ll result = 0;
    //from 00001 to 11111 or < 100000
    for (int i = 1; i < subset; i++) {
        ll onBit = __builtin_popcount(i);
        ll lcm = 1;
        for (int j = 0; j < 5; j++) {
            //is D[j] being used?
            if (i & (1 << j)) {
                lcm = lcm*D[j]/__gcd(lcm, D[j]);
            }

            //after this point, it's better to break to avoid overflow (won't change k later)
            if (lcm > end) break;
        }
        ll k = end/lcm;
        result += (onBit % 2 == 0 ? -k : k);
    }

    return result;
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, a, d;
        cin >> n >> m >> a >> d;
        for (int i = 0; i < 5; i++) {
            D[i] = a + i*d;
        }
        
        ll result = m-n+1 - (f(m) - f(n-1));
        cout << result << "\n";
    }

    return 0;
}