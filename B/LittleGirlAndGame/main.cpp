#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[250];

int main() {
    fast_io();
    //use ll when possible!
    string s; cin >> s;
    for (ll i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }

    ll rem = 0;
    for (ll ch = 'a'; ch <= 'z'; ch++) {
        if (cnt[ch] % 2 == 1) {
            rem++;
        }
    }

    if (rem == 0) {
        cout << "First\n";
    } else if ((rem - 1) % 2 == 0) {
        cout << "First\n";
    } else {
        cout << "Second\n";

    }

    return 0;
}