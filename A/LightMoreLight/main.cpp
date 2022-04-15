/*
the idea is that every number will have its factor and complement distinct, UNLESS that number is a perfect square so the factor and the complement is the same.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        long long n; cin >> n;
        if (n == 0) break;

        long long root = sqrt(n);
        if (root*root == n) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}