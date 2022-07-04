#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((double) a / b < (double) c / d) {
        swap(a, b);
        swap(c, d);
    }

    ll A = a*d - c*b;
    ll B = a*d;

    ll gcd = __gcd(A, B);
    A /= gcd;
    B /= gcd;
    cout << A << "/" << B << "\n";

    return 0;
}