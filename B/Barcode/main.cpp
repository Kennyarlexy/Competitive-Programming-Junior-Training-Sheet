#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char pixel[1005][1005];
int B[1005];
int W[1005];
int memo[1005][2];

int main() {
    memset(memo, -1, sizeof(memo));

    fast_io();
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pixel[i][j];
        }
    }

    int tempB = 0, tempW = 0;
    for (int c = 0; c < m; c++) {
        for (int r = 0; r < n; r++) {
            if (pixel[r][c] == '#') tempB++;
            else tempW++;
        }
        B[c] = tempB;
        W[c] = tempW;
    }

    memo[x-1][0] = W[x-1];
    memo[x-1][1] = B[x-1];

    for (int c = x; c < m; c++) {
        int start = max(c-y+1, 0);
        int end = c-x+1;

        int &bestB = memo[c][0];
        int &bestW = memo[c][1];
        for (int cc = start; cc <= end; cc++) {
            if (memo[cc-1][0] == -1) continue;
            int currentB = memo[cc-1][1] + (W[c] - W[cc-1]);
            int currentW = memo[cc-1][0] + (B[c] - B[cc-1]);
            bestB = (bestB == -1 ? currentB : min(currentB, bestB));
            bestW = (bestW == -1 ? currentW : min(currentW, bestW));
        }
    }
    int result = min(memo[m-1][0], memo[m-1][1]);
    cout << result << "\n";

    return 0;
}