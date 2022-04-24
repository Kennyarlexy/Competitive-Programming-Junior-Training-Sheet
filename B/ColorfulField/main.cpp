#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m, k, t; cin >> n >> m >> k >> t;
    int waste[k];
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        waste[i] = (a-1)*m + b;
    }
    for (int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        int cell = (a-1)*m + b;
        int count = 0;
        for (auto& w : waste) {
            if (cell == w) {
                count = -1;
                break;
            } else if (w < cell) {
                count++;
            }
        }
        int type = (cell - count) % 3;
        if (count == -1) {
            cout << "Waste\n";
        } else if (type == 1) {
            cout << "Carrots\n";
        } else if (type == 2) {
            cout << "Kiwis\n";
        } else if (type == 0) {
            cout << "Grapes\n";
        }
    }

    return 0;
}