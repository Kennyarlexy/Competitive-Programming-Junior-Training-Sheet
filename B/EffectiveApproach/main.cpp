#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int binarySearch(pair<int, int> num[], int target, int start, int end) {
    int loc = -1;
    while (true) {
        int mid = (start + end) / 2;
        if (num[mid].first > target) {
            end = mid - 1;
        } else if (num[mid].first < target) {
            start = mid + 1;
        } else {
            loc = mid;
            break;
        }
    }

    return num[loc].second;
}

int main() {
    int n; cin >> n;
    pair<int, int> num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i].first;
        num[i].second = i+1;
    }
    sort(num, num + n);
    int m; cin >> m;
    ll A = 0, B = 0;
    for (int i = 0; i < m; i++) {
        int target; cin >> target;
        int loc = binarySearch(num, target, 0, n - 1);
        int locReverse = n - loc + 1;
        A += loc;
        B += locReverse;
    }
    cout << A << " " << B << "\n";

    return 0;
}