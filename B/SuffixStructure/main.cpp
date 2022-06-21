#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int cntS[250];
int cntT[250];

int main() {
    fast_io();
    string s, t; cin >> s >> t;

    for (int i = 0; i < s.length(); i++) {
        cntS[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
        cntT[t[i]]++;
    }

    bool needTree = false;
    bool needAuto = false;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cntT[i] > cntS[i]) needTree = true;
        if (cntT[i] < cntS[i]) needAuto = true;
    }

    int j = 0;
    bool needArray = false;
    for (int i = 0; i < t.length(); i++) {
        while (j < s.length() && t[i] != s[j]) {
            j++;
        }
        if (j == s.length()){
            needArray = true;
            break;
        }
        j++;
    }

    if (needTree) cout << "need tree\n";
    else if (needAuto && needArray) cout << "both\n";
    else if (needAuto) cout << "automaton\n";
    else cout << "array\n";

    return 0;
}