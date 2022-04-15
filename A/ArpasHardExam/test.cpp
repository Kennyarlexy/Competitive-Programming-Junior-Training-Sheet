#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int original = n;
    n = (n % 3);
    int base = 6;

    if (n == 0 && original != 0) n = 3;
    int result = int(pow(base, n)) % 10;
    cout << result << "\n";
    
    return 0;
}