#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    ll n, m, x; cin >> n >> m >> x;
    bool hasShift = false;
    char key[n][m];
    set<char> exist;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> key[i][j];
            if (key[i][j] == 'S') hasShift = true;
            else exist.insert(key[i][j]);
        }
    }

    set<char> oneHand;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char ch = key[i][j];
            ll sr = fmax(0, i-x);
            ll er = fmin(n-1, i+x);
            ll sc = fmax(0, j-x);
            ll ec = fmin(m-1, j+x);
            for (ll r = sr; r <= er; r++) {
                for (ll c = sc; c <= ec; c++) {
                    if (key[r][c] == 'S') {
                        ll dr = r - i;
                        ll dc = c - j;
                        if (dr*dr + dc*dc <= x*x) oneHand.insert(ch);
                    }
                }
            }
        }
    }
    ll q; cin >> q;
    string T; cin >> T;
    ll count = 0;
    for (ll i = 0; i < q; i++) {
        char ch = T[i];
        if (exist.find(tolower(ch)) == exist.end()) {
            cout << "-1\n";
            return 0;
        } else if (ch >= 'a' && ch <= 'z') {
            continue;
        } else {
            if (!hasShift) {
                cout << "-1\n";
                return 0;
            } else if (oneHand.find(tolower(ch)) == oneHand.end()) count++;
        }
    }
    cout << count << "\n";

    return 0;
}