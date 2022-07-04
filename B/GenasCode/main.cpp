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
    ll n; cin >> n;
    ll cnt_0 = 0;
    bool zeroed = false;
    string sp = "1";
    string s;
    for (ll i = 1; i <= n; i++) {
        cin >> s;
        if (s[0] == '0') zeroed = true;
        if (!zeroed) {
            ll temp = 0;
            for (ll j = 1; j < s.length(); j++) {
                if (s[j] == '0') temp++;
            }
            if (temp == s.length() - 1 && s[0] == '1') {
                cnt_0 += temp;
            } else {
                sp = s;
            }
        }
    }
    if (zeroed) cout << "0\n";
    else {
        string res(cnt_0, '0');
        cout << sp << res << "\n";
    }

    return 0;
}