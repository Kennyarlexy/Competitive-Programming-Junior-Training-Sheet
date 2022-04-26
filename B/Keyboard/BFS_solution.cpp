#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

set<char> onehand;
int n, m, x; 
char key[200][200];
bool vis[200][200];

void bfs(int sr, int sc) {
    queue<int> qr;
    queue<int> qc;
    qr.push(sr);
    qc.push(sc);
    vis[sr][sc] = true;

    int dir_r[] = {1, 0, -1, 0};
    int dir_c[] = {0, 1, 0, -1};
    while (!qr.empty()) {
        int cr = qr.front();
        int cc = qc.front();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dir_r[i];
            int nc = cc + dir_c[i];
            int dr = nr - sr;
            int dc = nc - sc;
            if (vis[nr][nc]) continue;
            if (nr < 0 || nr > n - 1) continue;
            if (nc < 0 || nc > m - 1) continue;
            if (dr*dr + dc*dc > x*x) continue;
            vis[nr][nc] = true;
            qr.push(nr);
            qc.push(nc);
        }
        onehand.insert(key[cr][cc]);
        qr.pop();
        qc.pop();
    }
}


int main() {
    fast_io();
    cin >> n >> m >> x;
    vector<pair<int, int>> shift;
    set<char> exist;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            key[i][j] = ch;
            if (ch == 'S') shift.push_back(make_pair(i, j));
            else exist.insert(ch);
        }
    }
    int q; cin >> q;
    string T; cin >> T;

    for (auto& S : shift) {
        int r, c;
        tie(r, c) = S;
        fill((bool*)vis, (bool*)vis + sizeof(vis)/sizeof(bool), false);
        bfs(r, c);
    }
    int count = 0;
    for (auto& ch : T) {
        if (exist.find(tolower(ch)) == exist.end()) {
            cout << "-1\n";
            return 0;
        } else if (ch >= 'a' && ch <= 'z') {
            continue;
        } else {
            if (shift.size() == 0) {
                cout << "-1\n";
                return 0;
            } else if (onehand.find(tolower(ch)) == onehand.end()) {
                count++;
            }
        }
    }
    cout << count << "\n";

    return 0;
}