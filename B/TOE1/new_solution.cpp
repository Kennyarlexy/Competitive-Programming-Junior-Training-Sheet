#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    set<string> valid;
    queue<string> Q;

    string init = ".........";
    valid.insert(init);
    Q.push(init);

    bool Xturn = true;
    queue<string> temp;
    while (!Q.empty()) {
        string current = Q.front();
        Q.pop();
        
        char player = (Xturn ? 'X' : 'O');
        for (int i = 0; i < 9; i++) {
            if (current[i] != '.') continue;
            string next = current;
            next[i] = player;
            valid.insert(next);

            int c = i % 3, r = i - c;
            if (next[r] == next[r+1] && next[r+1] == next[r+2]) continue;
            if (next[c] == next[c+3] && next[c+3] == next[c+6]) continue;

            if (next[4] != '.' && next[0] == next[4] && next[4] == next[8]) continue;
            if (next[4] != '.' && next[2] == next[4] && next[4] == next[6]) continue;

            temp.push(next);
        }
        if (Q.empty()) {
            Q = temp;
            temp = queue<string> ();
            Xturn = !Xturn;
        }
    }
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string input;
        for (int j = 1; j <= 3; j++) {
            string s; cin >> s;
            input += s;
        }
        if (valid.find(input) != valid.end()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}