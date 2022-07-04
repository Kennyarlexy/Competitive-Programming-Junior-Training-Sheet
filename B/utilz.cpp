#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

//combination implementation
//be careful because some combinations are impossible, like C(1, 2); C(1, 5); C(99, 100); etc
ll C(ll n, ll r) {
    if (n < r) return 0;

    ll temp = 1;
    ll k = n - r;
    if (k < r) swap(k, r);
    for (ll x = n; x >= k+1; x--) {
        temp *= x;
        while (r >= 2 && temp % r == 0) {
            temp /= r;
            r--;
        }
    }

    return temp;
}

int main() {
    fast_io();
    //use ll when possible!

    return 0;
}