#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int cake[n+1];
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        cake[temp] = i;
    }
    int target = n;
    for (int line = 1; line <= n; line++) {
        while (line >= cake[target] && target > 0) {
            cout << target << " ";
            target--;
        }
        cout << "\n";
    }

    
    return 0;
}