#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int prev_r;
    int gap = 0;
    int first_l, last_r;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;

        if (i == 1) first_l = l;
        if (i == n) last_r = r;

        if (i > 1) {
            gap += l - prev_r - 1;
        }
        prev_r = r;
    }

    int elements = last_r - first_l + 1 - gap;
    int move = (k - (elements % k)) % k;
    cout << move << "\n";

    return 0;
}