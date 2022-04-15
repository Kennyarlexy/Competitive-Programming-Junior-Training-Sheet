#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    int height[n];
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int max = 0;
    int current = 0;
    while (current < n) {
        int countLeft = 0;
        int temp = current;
        while (temp > 0 && height[temp] >= height[temp-1]) {
            countLeft++;
            temp--;
        }

        temp = current;
        int countRight = 0;
        while (temp < n-1 && height[temp] >= height[temp+1]) {
            countRight++;
            temp++;
        }
        max = fmax(countLeft + countRight + 1, max);
        current += countRight + 1;
    }

    cout << max << "\n";

    return 0;
}