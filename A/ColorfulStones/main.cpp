#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, c; cin >> s >> c;
    int location = 1;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == s[location - 1]) {
            location++;
        }
    }
    cout << location << "\n";
    
    return 0;
}