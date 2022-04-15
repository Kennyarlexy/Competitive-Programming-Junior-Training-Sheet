#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int bird[n];
    for (int i = 0; i < n; i++) {
        cin >> bird[i];
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        int index = x - 1;
        int left = y - 1;
        int right = bird[index] - y;
        if (index >= 1) {
            bird[index-1] += left;
        }
        if (index <= n - 2) {
            bird[index+1] += right;
        }
        bird[index] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << bird[i] << "\n";
    }
    
    return 0;
}