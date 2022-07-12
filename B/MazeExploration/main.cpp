#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<string> grid;
bool vis[35][85];

void bfs(ll r, ll c) {
    queue<ll> qr;
    queue<ll> qc;
    qr.push(r); qc.push(c);
    vis[r][c] = true;
    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    while (!qr.empty()) {
        ll cr = qr.front(); qr.pop();
        ll cc = qc.front(); qc.pop();
        grid[cr][cc] = '#';
        for (ll dir = 0; dir < 4; dir++) {
            ll nr = cr + dr[dir];
            ll nc = cc + dc[dir];
            if (vis[nr][nc]) continue;
            if (nr < 0 || nr >= grid.size()) continue;
            if (nc < 0 || nc >= grid[nr].size()) continue;
            if (grid[nr][nc] != ' ') continue;

            vis[nr][nc] = true;
            qr.push(nr);
            qc.push(nc);
        }
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    //MUST IGNORE BEFORE USING GETLINE
    cin.ignore(10000, '\n');
    for (ll t = 1; t <= T; t++) {
        grid = vector<string> ();
        memset(vis, 0, sizeof(vis));
        string temp;
        while (true) {
            getline(cin, temp);
            if (temp[0] == '_') {
                break;
            }
            grid.push_back(temp);
        }
        for (ll r = 0; r < grid.size(); r++) {
            ll inside = false;
            for (ll c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] != '*' && grid[r][c] != '_' && grid[r][c] != ' ') {
                    inside = true;
                }
                if (grid[r][c] == '*' && inside) {
                    bfs(r, c);
                }
            }
        }

        for (auto& line : grid) {
            cout << line << "\n";
        }
        cout << temp << "\n";
    }

    return 0;
}