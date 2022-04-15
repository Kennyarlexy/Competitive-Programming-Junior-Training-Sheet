#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    for (int i = 0; i < str.length(); i++) {
        int WUBCount = 0;
        for (int j = i; j < str.length(); j += 3) {
            if (str.substr(j, 3) == "WUB") WUBCount++;
            else break;
        }
        if (WUBCount > 0) {
            str.replace(i, WUBCount * 3, " ");
        }
    }
    if (str[0] == ' ') {
        str.erase(0, 1);
    }
    if (str[str.length() - 1] == ' ') {
        str.erase(str.length() - 1, 1);
    }
    cout << str << "\n";
    
    return 0;
}