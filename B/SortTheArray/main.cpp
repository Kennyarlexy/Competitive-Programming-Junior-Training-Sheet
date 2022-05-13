#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int arr[100005];

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int l = 1, r = n;
    for (int i = 1; i <= n-1; i++) {
        if (arr[i] > arr[i+1]) {
            l = i;
            break;
        }
    }
    for (int i = l; i <= n-1; i++) {
        if (arr[i] < arr[i+1]) {
            r = i;
            break;
        }
    }

    reverse(arr+l, arr+r+1);
    bool OK = true;
    for (int i = 1; i <= n-1; i++) {
        if (arr[i] > arr[i+1]) {
            OK = false;
            break;
        }
    }
    if (OK) {
        cout << "yes\n";
        cout << l << " " << r << "\n";
    } else {
        cout << "no\n";
    }

    return 0;
}