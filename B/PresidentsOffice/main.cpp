#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    char C; cin >> C;
    char grid[105][105];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    set<char> distinct;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == C) {
                for (int i = 0; i < 4; i++) {
                    int adj_r = r + dir[i][0];
                    int adj_c = c + dir[i][1];
                    
                    if (adj_r < 0 || adj_r >= n || adj_c < 0 || adj_c >= m) continue;
                    if (grid[adj_r][adj_c] == '.' || grid[adj_r][adj_c] == C) continue;
                    
                    distinct.insert(grid[adj_r][adj_c]);
                }
            }
        }
    }

    cout << distinct.size() << "\n";


    return 0;
}