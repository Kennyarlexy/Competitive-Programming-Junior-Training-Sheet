#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int r, c, x; cin >> r >> c >> x;
    vector<pair<int, int>> alpha[1000];
    vector<pair<int, int>> shift;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char ch; cin >> ch;
            if (ch == 'S') shift.push_back(make_pair(i, j));
            else alpha[ch].push_back(make_pair(i, j));
        }
    }
    int q; cin >> q;
    string T; cin >> T;
    set<char> key;
    int keycount[1000];
    fill(keycount, keycount + 1000, 0);

    for (int i = 0; i < q; i++) {
        key.insert(T[i]);
        keycount[T[i]]++;
    }
    int count = 0;
    for (auto& ch : key) {
        if (alpha[tolower(ch)].size() == 0) {
            cout << "-1\n";
            return 0;
        } else if (ch >= 'a' && ch <= 'z') {
            continue;
        } else { //capital
            if (shift.size() == 0) {
                cout << "-1\n";
                return 0;
            }
            bool OK = false;
            for (auto& posalpha : alpha[tolower(ch)]) {
                for (auto& posshift : shift) {
                    int dr = abs(posalpha.first - posshift.first);
                    int dc = abs(posalpha.second - posshift.second);
                    if (pow(dr, 2) + pow(dc, 2) <= pow(x, 2)) {
                        OK = true;
                        goto done;
                    }
                }
            }
            done:
            if (!OK) count+=keycount[ch];
        }
    }
    cout << count << "\n";

    return 0;
}