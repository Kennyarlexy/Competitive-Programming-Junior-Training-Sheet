#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<char> letters;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        letters.insert(tolower(s[i]));
    }

    cout << (letters.size() == 26 ? "YES" : "NO") << "\n";
    
    return 0;
}