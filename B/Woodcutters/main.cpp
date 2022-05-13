#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int memo[100005][3];
int pos[100005];
int height[100005];

int main() {
    fast_io();
    memset(memo, -1, sizeof(memo));
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> height[i];
    }

    memo[0][0] = 0;
    memo[0][1] = 1;
    memo[0][2] = (pos[0] + height[0] < pos[1] ? 1 : 0);

    int prevMax = 1;
    for (int i = 1; i < n; i++) {
        memo[i][0] = prevMax;
        for (int j = 1; j < 3; j++) {
            int MAX = -1;
            for (int p = 0; p < 3; p++) {
                int prev = memo[i-1][p];
                if (prev == -1) continue;

                int edgel = (p <= 1 ? pos[i-1] : pos[i-1] + height[i-1]);
                if (j == 1 && pos[i] - height[i] > edgel)
                    MAX = max(MAX, prev + 1);
                else if (j == 2 && (pos[i] + height[i] < pos[i+1] || i == n-1)) 
                    MAX = max(MAX, prev + 1);
            }
            memo[i][j] = MAX;
            prevMax = max(prevMax, MAX);
        }
    }

    int result = 0;
    for (int j = 0; j < 3; j++) {
        result = max(result, memo[n-1][j]);
    }
    cout << result << "\n";

    return 0;
}