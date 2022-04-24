#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    vector<bool> init(101, false);
    vector<bool> arr[101];
    arr[0] = init;
    for (int i = 1; i <= 100; i++) {
        vector<bool> temp = arr[i-1];
        for (int j = i; j <= 100; j+=i) {
            temp[j] = !temp[j];
        }
        arr[i] = temp;
    }
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[n][i]) count++;
        }
        cout << count << "\n";
    }

    return 0;
}