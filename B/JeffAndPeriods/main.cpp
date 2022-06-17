#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int p[100005];
int d[100005];
bool invalid[100005];
bool exist[100005];

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        exist[a] = true;
        if (p[a] != 0) {
            int diff = i - p[a];
            if (d[a] == 0) d[a] = diff;
            else if (diff != d[a]) invalid[a] = true;
        }
        p[a] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= 100000; i++) {
        if (exist[i] && !invalid[i]) cnt++;
    }

    cout << cnt << "\n";
    for (int i = 1; i <= 100000; i++) {
        if (!exist[i] || invalid[i]) continue;
        cout << i << " " << d[i] << "\n";
    }

    return 0;
}