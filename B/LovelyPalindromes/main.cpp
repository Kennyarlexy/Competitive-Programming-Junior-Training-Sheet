#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    string n; cin >> n;
    cout << n;
    for (int i = n.length() - 1; i >= 0; i--) {
        cout << n[i];
    }
    cout << "\n";

    return 0;
}