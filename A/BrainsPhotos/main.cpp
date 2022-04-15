#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c; 
    bool colored = false;
    for (int row = 1; row <= r; row++) {
        for (int col = 1; col <= c; col++) {
            char temp; cin >> temp;
            if (temp == 'C' || temp == 'M' || temp == 'Y') {
                colored = true;
            }
        }
    }
    if (colored) cout << "#Color\n";
    else cout << "#Black&White\n";
    
    return 0;
}