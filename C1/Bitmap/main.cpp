#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll N, M;
char grid[200][200];
bool vis[200][200];
ll dist[200][200];

ll bfs(ll r, ll c) {
    queue<ll> qr, qc;
    qr.push(r);
    qc.push(c);
    vis[r][c] = true;
    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    while (!qr.empty()) {
        ll cr = qr.front(); qr.pop();
        ll cc = qc.front(); qc.pop();
        dist[cr][cc] = min(dist[cr][cc], abs(cr - r) + abs(cc - c));
        for (ll dir = 0; dir < 4; dir++) {
            ll nr = cr + dr[dir];
            ll nc = cc + dc[dir];
            if (vis[nr][nc]) continue;
            if (nr <= 0 || nr > N) continue;
            if (nc <= 0 || nc > M) continue;
            if (grid[nr][nc] == '1') continue;
            
            vis[nr][nc] = true;
            qr.push(nr);
            qc.push(nc);
        }
    }

    return 0;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin >> N >> M;
        for (ll i = 0; i < 200; i++) {
            for (ll j = 0; j < 200; j++) {
                dist[i][j] = LONG_LONG_MAX;
            }
        }

        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= M; j++) {
                cin >> grid[i][j];
            }
        }

        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= M; j++) {
                if (grid[i][j] == '1') {
                    memset(vis, 0, sizeof(vis));
                    bfs(i, j);
                }
            }
        }

        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= M; j++) {
                cout << dist[i][j];
                if (j < M) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}