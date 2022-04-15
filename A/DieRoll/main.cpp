#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y, W; cin >> Y >> W;
    int nominator = 7 - fmax(Y, W);
    int dominator = 6;
    
    for (int i = 6; i >= 2; i--) {
        if (nominator % i == 0 && dominator % i == 0) {
            nominator /= i, dominator /= i;
        }
        if (nominator == 1 || dominator == 1) break;
    }
    cout << nominator << "/" << dominator << "\n";
    
    return 0;
}