#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int currentPetr, b, currentTaxi, d; cin >> currentPetr >> b >> currentTaxi >> d;
    int prevTaxi = INT_MAX;
    while (true) {
        if (currentPetr >= prevTaxi) {
            cout << prevTaxi << "\n";
            break;
        } else if (currentTaxi <= currentPetr) {
            cout << currentPetr << "\n";
            break;
        }
        prevTaxi = currentTaxi;
        currentPetr += b;
        currentTaxi -= d;
    }

    return 0;
}