#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int coin[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        total += coin[i];
    }
    sort(coin, coin + n, greater<int>());
    int half = total / 2 + 1;

    int current = 0;

    int i = 0;
    while (current < half) {
        current += coin[i];
        i++;
    }
    cout << i << "\n";

    
    return 0;
}