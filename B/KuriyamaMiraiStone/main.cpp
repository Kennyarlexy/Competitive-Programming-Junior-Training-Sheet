#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll sum1[n];
    ll temp1 = 0;
    for (int i = 0; i < n; i++) {
        temp1 += arr[i];
        sum1[i] = temp1;
    }

    sort(arr, arr + n);
    ll sum2[n];
    ll temp2 = 0;
    for (int i = 0; i < n; i++) {
        temp2 += arr[i];
        sum2[i] = temp2;
    }
    
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1) {
            ll result = (l > 1 ? sum1[r-1] - sum1[l-2] : sum1[r-1]);
            cout << result << "\n";
        } else {
            ll result = (l > 1 ? sum2[r-1] - sum2[l-2] : sum2[r-1]);
            cout << result << "\n";
        }
    }

    return 0;
}