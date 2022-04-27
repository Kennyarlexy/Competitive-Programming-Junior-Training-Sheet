#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool vis[10][10];
int dist[10][10];

void fewestMove(ll sr, ll sc, ll er, ll ec) {
    queue<int> qr, qc;
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = true;

    while(!qr.empty()) {
        ll cr = qr.front(); //current row
        ll cc = qc.front(); //current column
        ll dr[] = {-1, -2, -2, -1, 1, 2, 2, 1}; //delta r
        ll dc[] = {-2, -1, 1, 2, -2, -1, 1, 2}; //delta c
        for (ll i = 0; i < 8; i++) {
            ll next_r = cr + dr[i];
            ll next_c = cc + dc[i];
            if (vis[next_r][next_c]) continue;
            if (next_r < 0 || next_r > 7) continue;
            if (next_c < 0 || next_c > 7) continue;
            dist[next_r][next_c] = dist[cr][cc] + 1;
            qr.push(next_r);
            qc.push(next_c);
            if (cr == er && cc == ec) return;
        }
        qr.pop();
        qc.pop();
    }
}

int main() {
    fast_io();
    string start, end;
    while (cin >> start >> end) {
        fill((bool*) vis, (bool*) vis + 100, false);
        ll sc = start[0] - 'a';
        ll sr = start[1] - '1';
        ll ec = end[0] - 'a';
        ll er = end[1] - '1';
        dist[sr][sc] = 0;
        fewestMove(sr, sc, er, ec);
        cout << "To get from " << start << " to " << end << " takes " << dist[er][ec] << " knight moves.\n";
    }

    return 0;
}