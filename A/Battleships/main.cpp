#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char grid[105][105];

bool dfs(int cr, int cc, int dr, int dc, int N, int len = 2) {
    if (len > N/2) return false;
    if (cr < 0 || cr >= N) return false;
    if (cc < 0 || cc >= N) return false;
    if (grid[cr][cc] == '.') return false;

    bool alive = dfs(cr+dr, cc+dc, dr, dc, N, len+1) || grid[cr][cc] == 'x';
    grid[cr][cc] = '.';

    return alive;
}

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }

        int cnt = 0;
        int dr[] = {1, 0};
        int dc[] = {0, 1};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '.') continue;
                
                bool alive = grid[i][j] == 'x';
                for (int dir = 0; dir < 2; dir++) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];
                    alive = dfs(nr, nc, dr[dir], dc[dir], N) || alive;
                }
                if (alive) cnt++;
                grid[i][j] = '.';
            }
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }

    return 0;
}