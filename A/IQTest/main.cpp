#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    char arr[5][5];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            int count = 0;
            if (arr[i][j] == '#') count++;
            if (arr[i][j+1] == '#') count++;
            if (arr[i+1][j] == '#') count++;
            if (arr[i+1][j+1] == '#') count++;
            if (count >= 3 || count <= 1) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}