#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    set<int> SS;
    bool possible = true;
    for (int i = 1; i <= n; i++) {
        string line; cin >> line;
        int G, S;
        for (int i = 0; i < m; i++) {
            if (line[i] == 'G') G = i;
            else if (line[i] == 'S') S = i;
        }
        int dist = S - G;
        if (dist > 0) {
            SS.insert(dist);
        } else {
            possible = false;
        }
    }

    if (possible) {
        cout << SS.size() << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}