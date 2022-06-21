#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int A[100005];

int first[5005];
int last[5005];

int main() {
    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    memset(first, -1, sizeof(first));
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A, A + n);
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] > prev) first[A[i]] = i;
        last[A[i]] = i;
        prev = A[i];
    }

    int res = INT_MAX;

    // cout << first[3] << " " << last[8] << "\n";
    for (int i = 1; i <= 5000; i++) {
        if (first[i] == -1) continue;

        for (int j = min(i*2, 5000); j >= i; j--) {
            if (last[j] == -1) continue;
            int temp = first[i] + (n - 1 - last[j]);
            res = min(res, temp);
            break;
        }
    }
    cout << res << "\n";

    return 0;
}