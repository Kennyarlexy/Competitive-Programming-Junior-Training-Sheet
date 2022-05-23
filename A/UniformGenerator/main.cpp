#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int a, b; 
    while (cin >> a >> b) {
        string result;
        if (__gcd(a, b) == 1) {
            result = "Good Choice";
        } else {
            result = "Bad Choice";
        }
        cout.width(10);
        cout << a;
        cout.width(10);
        cout << b;
        cout << "    " << result << "\n\n";
    }

    return 0;
}