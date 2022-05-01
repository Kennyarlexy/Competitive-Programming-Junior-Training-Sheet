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
    Q.push(init);

    bool Xturn = true;
    queue<string> temp;
    while (!Q.empty()) {
        string current = Q.front();
        Q.pop();
        
        char player = (Xturn ? 'X' : 'O');
        int count = 0;
        for (int i = 0; i < 9; i++) {
            if (current[i] != '.') {
                count++;
                continue;
            }
            string next = current;
            next[i] = player;

            int c = i % 3, r = i - c;
            if ((next[r] == next[r+1] && next[r+1] == next[r+2]) || 
            (next[c] == next[c+3] && next[c+3] == next[c+6]) ||
            (next[4] != '.' && next[0] == next[4] && next[4] == next[8]) ||
            (next[4] != '.' && next[2] == next[4] && next[4] == next[6])) {
                valid.insert(next);
            } else {
                temp.push(next);
            }
        }
        if (count == 9) valid.insert(current);

        if (Q.empty()) {
            Q = temp;
            temp = queue<string> ();
            Xturn = !Xturn;
        }
    }
    
    while (true) {
        string input; cin >> input;
        if (input == "end") break;
        if (valid.find(input) != valid.end()) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
    
    return 0;
}