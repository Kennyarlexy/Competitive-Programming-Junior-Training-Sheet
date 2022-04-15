#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int original = n;
    n = (n % 4);
    // 4 in the expression above comes from the fact that the remainder will repeat (loop) again every multiples of 4 (kelipatan 4) in the case of base = 8. This will also apply for every base cases.
    
    int base = 8;

    if (n == 0 && original != 0) n = 4;
    int result = int(pow(base, n)) % 10;
    cout << result << "\n";
    
    return 0;
}