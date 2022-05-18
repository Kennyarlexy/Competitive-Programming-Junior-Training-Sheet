#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int pos[100005];
int height[100005];

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> height[i];
    }

    int prevOcc = pos[0];
    int count = (n > 1 ? 2 : 1);
    for (int i = 1; i < n-1; i++) {
        int curOcc = pos[i];
        if (pos[i] - height[i] > prevOcc) {
            count++;
        }
        else if (pos[i] + height[i] < pos[i+1]) {
            count++;
            curOcc += height[i];
        }
        prevOcc = curOcc;
    }
    cout << count << "\n";

    return 0;
}