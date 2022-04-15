#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<bool> exist(k+1);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        fill(exist.begin(), exist.end(), false);
        bool good = true;
        int a; cin >> a;
        while (a > 0) {
            int digit = a % 10;
            if (digit <= k) {
                exist[digit] = true;
            }
            a /= 10;
        }
        for (int i = 0; i <= k; i++) {
            if (exist[i] == false) {
                good = false;
                break;
            }
        }
        if (good) count++;
    }
    cout << count << "\n";

    return 0;
}