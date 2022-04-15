#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    unsigned long long x;
    cin >> n >> x;
    int countDistress = 0;
    for (int i = 0; i < n; i++) {
        char sign; cin >> sign;
        int d; cin >> d;
        if (sign == '-') {
            if (x >= d) {
                x -= d;
            } else {
                countDistress++;
            }
        } else {
            x += d;
        }
    }
    cout << x << " " << countDistress << "\n";
    
    return 0;
}