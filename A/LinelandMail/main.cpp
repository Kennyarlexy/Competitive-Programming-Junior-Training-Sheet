#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int coordinate[n];
    for (int i = 0; i < n; i++) {
        cin >> coordinate[i];
    }

    for (int i = 0; i < n; i++) {
        int closeLeft = INT_MAX, closeRight = INT_MAX;
        if (i < n-1) {
            closeRight = coordinate[i+1] - coordinate[i];
        }
        if (i > 0) {
            closeLeft = coordinate[i] - coordinate[i-1];
        }

        int close = (closeLeft < closeRight ? closeLeft : closeRight);
        int far = fmax(coordinate[i] - coordinate[0], coordinate[n-1] - coordinate[i]);
        cout << close << " " << far << "\n";
    }
    
    return 0;
}