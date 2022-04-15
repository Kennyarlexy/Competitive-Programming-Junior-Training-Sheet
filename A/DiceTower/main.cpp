#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, top; cin >> n >> top;
    bool possible = true;
    int prev_bot;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            prev_bot = 7 - top;
        }
        int a, b; cin >> a >> b;
        int c = 7-a;
        int d = 7-b;
        int arr[] = {a, b, c, d};
        for (int j = 0; j < 4; j++) {
            if (arr[j] == prev_bot) {
                possible = false;
                break;
            }
        }
        prev_bot = 7 - prev_bot;
    }
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}