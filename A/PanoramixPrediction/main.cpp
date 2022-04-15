#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    bool prime = true;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {
    int n, m; cin >> n >> m;

    bool OK = true;
    if (!isPrime(m)) OK = false;
    else {
        for (int i = n+1; i < m; i++) {
            if (isPrime(i)) {
                OK = false;
                break;
            }
        }
    }
    
    if (OK) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}