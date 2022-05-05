#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool ZRA[1005], XRA[2005]; //X Ready At

int main() {
    fast_io();
    int p, q, l, r; cin >> p >> q >> l >> r;

    int max = 0;
    for (int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        max = fmax(max, b);
        for (int t = a; t <= b; t++) {
            ZRA[t] = true;
        }
    }

    for (int i = 0; i < q; i++) {
        int c, d; cin >> c >> d;
        for (int t = c; t <= d; t++) {
            XRA[t+1000] = true;
        }
    }
    
    int result = 0;
    for (int t = l; t <= r; t++) {
        for (int i = t; i <= max; i++) {
            if (ZRA[i] && XRA[1000+i-t]) {
                result++;
                break;
            }
        }
    }
    cout << result << "\n";

    return 0;
}