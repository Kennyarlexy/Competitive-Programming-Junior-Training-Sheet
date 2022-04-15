#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int h; cin >> h;
        max = fmax(max, h);
    }
    cout << max << "\n";

    return 0;
}