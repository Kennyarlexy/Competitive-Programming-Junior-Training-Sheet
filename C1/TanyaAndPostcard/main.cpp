#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cntS[300];
ll cntT[300];

int main() {
    fast_io();
    //use ll when possible!
    string s, t;
    cin >> s >> t;

    for (ll i = 0; i < s.length(); i++) {
        cntS[s[i]]++;
    }

    for (ll i = 0; i < t.length(); i++) {
        cntT[t[i]]++;
    }

    ll yay = 0;
    for (char ch = 'A'; ch <= 'z'; ch++) {
        ll tyay = min(cntS[ch], cntT[ch]);
        cntS[ch] -= tyay;
        cntT[ch] -= tyay;
        yay += tyay;
    }
    
    ll whoops = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        ll twhoops = min(cntS[ch], cntT[tolower(ch)]);
        whoops += twhoops;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        ll twhoops = min(cntS[ch], cntT[toupper(ch)]);
        whoops += twhoops;
    }

    cout << yay << " " << whoops << "\n";

    return 0;
}