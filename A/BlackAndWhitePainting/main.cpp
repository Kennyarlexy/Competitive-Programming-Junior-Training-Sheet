#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m, c;
    while(true) {
        cin >> n >> m >> c;
        if (n == 0 && m == 0 && c == 0) break;
        ll result = ((m-7)*(n-7)+c) / 2;
        cout << result << "\n";
    }
    
    return 0;
}