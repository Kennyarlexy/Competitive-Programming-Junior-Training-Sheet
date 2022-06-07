#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    string s; cin >> s;
    int first = -1;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (first == -1) first = i;
            count++;
        }
    }

    int revi = s.length()-1-first;
    int result = (first == -1 ? 0 : revi / 2);

    if ((revi % 2 == 1 || count > 1) && count > 0) {
        result++;
    }
    cout << result << "\n";

    return 0;
}