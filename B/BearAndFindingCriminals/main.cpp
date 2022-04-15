#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, a; cin >> n >> a;
    int criminal[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> criminal[i];
    }

    int left = a, right = a;
    int count= 0;
    while (left >= 1 || right <= n) {
        if (left <= 0 && criminal[right] == 1) {
            count++;
        } else if (right > n && criminal[left] == 1) {
            count++;
        } else if (criminal[left] == 1 && criminal[right] == 1) {
            if (left == right) {
                count += 1;
            } else {
                count += 2;
            }
        }
        left--;
        right++;
    }

    cout << count << "\n";

    return 0;
}