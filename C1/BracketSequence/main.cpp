#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool isC[300];
char O[300];

ll res[100005];

int main() {
    fast_io();
    //use ll when possible!
    isC[')'] = isC['}'] = isC[']'] = isC['>'] = true;

    O[')'] = '(';
    O['}'] = '{';
    O[']'] = '[';
    O['>'] = '<';

    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string s; cin >> s;
        memset(res, 0, sizeof(ll) * s.length());
        stack<pair<char, ll>> S;
        ll k = 0;
        for (ll i = s.length() - 1; i >= 0; i--) {
            if (isC[s[i]]) { //is closing tag
                S.emplace(s[i], k);
                k = 0;
            } else if (!S.empty()) { //is open tag, check if there is some closing tags in S
                char ch;
                ll tk;
                tie(ch, tk) = S.top();
                if (O[ch] == s[i]) { //match
                    k += tk + 2; //we have a total length k of valid tags
                    res[i] = k;
                    S.pop();
                } else { //not match, complete reset, as you can never connect any left i with right i anymore
                    S = {};
                    k = 0;
                }
            } else { //is open tag, but S is empty
                k = 0;
            }
        }
        cout << "Case " << t << ":\n";
        for (ll i = 0; i < s.length(); i++) {
            cout << res[i] << "\n";
        }
    }

    return 0;
}