#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char grid[30][30];
int n;


void bfs(int sr, int sc) {
    queue<int> qr;
    queue<int> qc;
    qr.push(sr);
    qc.push(sc);
    grid[sr][sc] = '0';
    
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (!qr.empty()) {
        int cr = qr.front(); qr.pop();
        int cc = qc.front(); qc.pop();
        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n) continue;
            if (nc < 0 || nc >= n) continue;
            if (grid[nr][nc] == '0') continue;

            qr.push(nr);
            qc.push(nc);
            grid[nr][nc] = '0';
        }
    }
}

int main() {
    fast_io();
    int k = 0;
    while (cin >> n) {
        k++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                bfs(i, j);
                result++;
            }
        }
        cout << "Image number " << k << " contains " << result << " war eagles.\n";
    }

    return 0;
}