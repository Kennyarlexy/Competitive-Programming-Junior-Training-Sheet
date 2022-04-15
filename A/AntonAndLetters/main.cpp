#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    set<char> set;
    for (int i = 1; i < s.length() - 1; i+=3) {
        if (set.find(s[i]) == set.end()) {
            set.insert(s[i]);
        }
    }
    cout << set.size() << "\n";

    return 0;
}