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
    string str1, str2;
    while (getline(cin, str1)) {
        vector<ll> C;
        stringstream line1(str1);
        ll c;
        while (line1 >> c) {
            C.push_back(c);
        }

        getline(cin, str2);
        stringstream line2(str2);
        ll x;
        ll cnt = 0;
        while (line2 >> x) {
            cnt++;
            if (cnt > 1) cout << " ";
            vector<ll> X;
            X.push_back(1);
            for (ll i = 1; i < C.size(); i++) {
                X.push_back(X[i-1] * x);
            }

            ll res = 0;
            for (ll i = 0, j = X.size() - 1; i < C.size(); i++, j--) {
                res += C[i] * X[j];
            }

            cout << res;
        }
        cout << "\n";
    }

    return 0;
}