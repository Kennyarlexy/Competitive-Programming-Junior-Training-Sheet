#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    string s; cin >> s;
    bool after2 = false;
    ll cnt0 = 0, cnt1 = 0;
    string seg1, seg2, seg3;
    for (ll i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (after2) seg3 += '0';
            else seg1 += '0';
        } else if (s[i] == '1') {
            seg2 += '1';
        } else {
            after2 = true;
            seg3 += '2';
        }
    }
    cout << seg1 << seg2 << seg3 << "\n";

    return 0;
}