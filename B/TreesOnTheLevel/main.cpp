#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

map<string, ll> id[260];

int main() {
    fast_io();
    //use ll when possible!
    string s;
    while (cin >> s) {
        fill(id, id+260, map<string, ll> ()); //memset doesn't work
        bool OK = true;
        ll deepest = 0;
        while (s != "()") {
            ll len = s.length();
            ll pk = s.find(',');
            ll lvl = len - 2 - pk;
            deepest = max(deepest, lvl);
            ll idtemp = stoll(s.substr(1, pk - 1));
            
            map<string, ll>::iterator it;
            bool ins;
            tie(it, ins) = id[lvl].emplace(s.substr(pk + 1, lvl), idtemp);
            if (!ins) OK = false;

            cin >> s;
        }

        if (OK) OK = id[0].size() == 1;
        if (OK) {
            for (ll lvl = deepest; lvl > 0 && OK; lvl--) {
                for (auto& data : id[lvl]) {
                    string path = data.first;
                    OK = id[lvl-1].find(path.substr(0, lvl-1)) != id[lvl-1].end();

                    if (!OK) break;
                }
            }
        }

        if (OK) {
            for (ll lvl = 0; lvl <= deepest; lvl++) {
                ll cnt = 0;
                ll size = id[lvl].size();
                for (auto& data : id[lvl]) {
                    cnt++;
                    cout << data.second;
                    if (lvl != deepest || cnt < size) cout << " ";
                }
            }
            cout << "\n";
        } else {
            cout << "not complete\n";
        }
    }
    // cout << "No error\n";

    return 0;
}