#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int x = 2*n + 1;
    int vertices[x+1];
    for (int i = 1; i <= x; i++) {
        cin >> vertices[i];
    }

    for (int i = 2; i <= x-1; i+=2) {
        if (k == 0) break;
        if (vertices[i] - vertices[i-1] >= 2 && vertices[i] - vertices[i+1] >= 2) {
            vertices[i]--;
            k--;
        }
    }

    for (int i = 1; i <= x; i++) {
        cout << vertices[i] << " ";
    }
    cout << "\n";

    return 0;
}