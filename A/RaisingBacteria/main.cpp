#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int x; cin >> x;
    int count = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            count++;
        }
        x /= 2;
    }
    cout << count << "\n";

    return 0;
}