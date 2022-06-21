#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool exist[100];

int main() {
    fast_io();
    string s; cin >> s;
    int len = s.length();
    bool OK = false;
    for (int i = 0; i + 25 < len; i++) {
        memset(exist, 0, sizeof(exist));
        OK = true;
        for (int j = i; j < i + 26; j++) {
            if (s[j] != '?' && exist[s[j]]) {
                OK = false;
                break;
            }
            exist[s[j]] = true;
        }

        if (OK) {
            int j = i;
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                if (exist[ch]) continue;
                while (s[j] != '?') j++;
                s[j] = ch;
            }
            break;
        }
    }
    
    if (OK) {
        for (int i = 0; i < len; i++) {
            if (s[i] == '?') s[i] = 'A';
        }
        cout << s << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}