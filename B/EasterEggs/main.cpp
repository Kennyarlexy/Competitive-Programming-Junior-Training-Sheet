#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    string colors = "ROYGBIV";
    cout << "ROY";
    for (int i = 0; i < n - 3; i++) {
        int color = i % 4 + 3;
        cout << colors[color];
    }
    cout << "\n";

    return 0;
}