#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n; cin >> n;
    stack<int> S;
    int count = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        int w, h; cin >> w >> h;
        while (!S.empty() && h < S.top()) {
            S.pop();
        }
        if (S.empty() || h > S.top()) {
            S.push(h);
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}