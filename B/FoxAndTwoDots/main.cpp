#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, m;
char grid[55][55];
bool vis1[55][55];
bool vis2[55][55];

bool dfs(ll r, ll c, ll pr = -1, ll pc = -1) {
    if (vis1[r][c]) {
        return vis2[r][c];
    }

    vis1[r][c] = true;
    vis2[r][c] = true;
    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    bool cyclic = false;
    for (ll dir = 0; dir < 4; dir++) {
        ll nr = r + dr[dir];
        ll nc = c + dc[dir];
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= m) continue;
        if (grid[nr][nc] != grid[r][c]) continue;
        if (nr == pr && nc == pc) continue;

        if (dfs(nr, nc, r, c)) {
            cyclic = true;
            break;
        }
    }
    vis2[r][c] = false;

    return cyclic;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> n >> m;
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < m; c++) {
            cin >> grid[r][c];
        }
    }

    bool cyclic = false;
    for (ll r = 0; r < n; r++) {
        for (ll c = 0; c < m; c++) {
            if (vis1[r][c]) continue;
            if (dfs(r, c)) {
                cyclic = true;
                goto exit;
            }
        }
    }

    exit:
    if (cyclic) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}