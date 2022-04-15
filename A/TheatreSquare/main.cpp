#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a; cin >> n >> m >> a;

    //both works

    // long long width_s = (n % a == 0 ? n/a : n/a + 1);
    // long long height_s = (m % a == 0 ? m/a : m/a + 1);

    long long width_s = (n-1)/a + 1;
    long long height_s = (m-1)/a + 1;
    
    long long result = width_s*height_s;
    cout << result << "\n";
    
    return 0;
}