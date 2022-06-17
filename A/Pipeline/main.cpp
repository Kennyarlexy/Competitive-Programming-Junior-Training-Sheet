#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    unsigned ll n, k; cin >> n >> k;

    unsigned ll total = (k-1) * (2 + k) / 2 - (k-2);
    if (n > total) {
        cout << "-1\n";
        return 0;
    } else if (n == total) {
        unsigned ll res = k-1;
        cout << res << "\n";
        return 0;
    }

    unsigned ll used = 0;
    bool OK = false;
    for (unsigned ll step = (k-1)/2; step >= 1; step/=2) {
        while (true) {
            unsigned ll temp = used + step;
            unsigned ll a = k-temp+1;
            unsigned ll b = k;
            unsigned ll sum = (temp * (a+b) / 2) - (temp-1);

            if (sum > n) break;

            used = temp;
            unsigned ll next = a-1;
            unsigned ll remainder = n - sum;
            if (next > remainder) {
                if (remainder > 0) used++;
                OK = true;
                break;
            }
        }
        if (OK) break;
    }

    cout << used << "\n";

    return 0;
}