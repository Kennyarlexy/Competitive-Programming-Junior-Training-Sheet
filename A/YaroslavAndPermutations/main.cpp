#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    int arr[1001];
    fill(arr, arr+1001, 0);

    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        arr[val]++;
    }

    int max = 0;
    for (int i = 1; i <= 1000; i++) {
        if (arr[i] > max) max = arr[i];
    }
    if (max <= (n % 2 == 0 ? n/2 : (n+1)/2)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}