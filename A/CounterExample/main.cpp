#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r; cin >> l >> r;
    if (l > r) swap(l, r);
    if (l % 2 != 0) l++;

    if (r - l >= 2) {
        cout << l << " " << l+1 << " " << l+2 << "\n";
    } else {
        cout << "-1\n";
    }
    
    return 0;
}