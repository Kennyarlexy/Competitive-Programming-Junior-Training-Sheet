#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int memo[100][3];
bool pos[3];

int main() {
    fast_io();
    int n; cin >> n;
    memset(memo, -1, sizeof(memo));
    
    for (int i = 0; i < n; i++) {
        memset(pos, false, sizeof(pos));
        int a; cin >> a;
        if (a == 1) pos[1] = true;
        else if (a == 2) pos[2] = true;
        else if (a == 3) pos[1] = true, pos[2] = true;
        pos[0] = true;

        //modify current day
        for (int j = 0; j < 3; j++) {
            if (!pos[j]) continue;

            if (i == 0) {
                memo[i][j] = (j == 0 ? 0 : 1);
                continue;
            }

            int MAX = -1;
            //check prev day
            for (int k = 0; k < 3; k++) {
                int prev = memo[i-1][k];
                if (prev == -1) continue;
                if (j != k && j != 0) prev++;
                MAX = max(MAX, prev);
            }
            memo[i][j] = MAX;
        }
    }

    int active = 0;
    for (int i = 0; i < 3; i++) {
        active = max(active, memo[n-1][i]);
    }
    int result = n - active;
    cout << result << "\n";

    return 0;
}