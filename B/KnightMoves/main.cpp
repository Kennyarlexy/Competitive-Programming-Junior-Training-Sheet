#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool vis[10][10];
queue<int> qr, qc;


int exploreNeighbours(int cr, int cc,  int er, int ec) {
    int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1}; //delta r
    int dc[] = {-2, -1, 1, 2, -2, -1, 1, 2}; //delta c
    int nextDistMove = 0;
    for (int i = 0; i < 8; i++) {
        int next_r = cr + dr[i];
        int next_c = cc + dc[i];
        if (!vis[next_r][next_c] && 
            (next_r >= 0 && next_r < 8) && 
            (next_c >= 0 && next_c < 8)
        ) {
            nextDistMove++;
            qr.push(next_r);
            qc.push(next_c);
            vis[next_r][next_c] = true;
        }
    }

    return nextDistMove;
}

int fewestMove(int sr, int sc, int er, int ec) {
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = true;

    int curDistMove = 0, nextDistMove = 0;
    int moves = 0;
    int distance = 0;
    bool found = false;
    while(!qr.empty()) {
        int cr = qr.front(); //current row
        int cc = qc.front(); //current column
        if (cr == er && cc == ec) {
            moves = distance;
            found = true;
        }
        if (!found) nextDistMove += exploreNeighbours(cr, cc, er, ec);
        if (curDistMove == 0) {
            curDistMove = nextDistMove;
            nextDistMove = 0;
            distance++;
        }
        curDistMove--;
        qr.pop();
        qc.pop();
    }

    return moves;
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
        ll moves = fewestMove(sr, sc, er, ec);
        cout << "To get from " << start << " to " << end << " takes " << moves << " knight moves.\n";
    }

    return 0;
}