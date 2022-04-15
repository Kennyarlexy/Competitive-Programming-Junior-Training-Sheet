#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int stew[n];
    for (int i = 0; i < n; i++) {
        cin >> stew[i];
    }
    sort(stew, stew + n);

    int total = 0;
    if (n >= 3 && stew[n-1] - stew[0] >= 2) {
        for (int i = 1; i < n-1; i++) {
            if (stew[i] != stew[0] && stew[i] != stew[n-1]) {
                total++;
            }
        }
    }
    cout << total << "\n";
    
    return 0;
}