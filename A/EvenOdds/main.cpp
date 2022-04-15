#include <bits/stdc++.h>
using namespace std;

long long getResult(long long n, long long k) {
    long long even  = n / 2;
    long long odd = n - even;
    if (k > odd) {
        return (k-odd)*2;
    } else {
        return (k*2 - 1);
    }
}

int main() {
    long long n, k; cin >> n >> k;
    
    long long result = getResult(n, k);
    cout << result << "\n";

    return 0;
}