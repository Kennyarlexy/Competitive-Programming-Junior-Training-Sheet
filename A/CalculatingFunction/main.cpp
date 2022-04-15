#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    
    if (n % 2 == 1) {
        long long result = (n / 2 + 1) * -1;
        cout << result << "\n";
    } else {
        long long result = n / 2;
        cout << result << "\n";
    }
    
    return 0;
}