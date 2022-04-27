#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }

        return hash1;
    }
};

unordered_map<pair<int, int>, bool, hash_pair> V; //allowed
unordered_map<pair<int, int>, int, hash_pair> dist;

void bfs(int r0, int c0, int r1, int c1) {
    queue<int> qr, qc;
    qr.push(r0);
    qc.push(c0);
    V[{r0, c0}] = true;

    int dir_r[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dir_c[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    while (!qr.empty()) {
        int cr = qr.front();
        int cc = qc.front();
        for (int i = 0; i < 8; i++) {
            int next_r = cr + dir_r[i];
            int next_c = cc + dir_c[i];
            if (V.find({next_r, next_c}) == V.end()) continue;
            if (V[{next_r, next_c}]) continue;
            
            V[{next_r, next_c}] = true;
            qr.push(next_r);
            qc.push(next_c);
            dist.insert({{next_r, next_c}, dist[{cr, cc}] + 1});
            if (cr == r1 && cc == c1) break;
        }
        qr.pop();
        qc.pop();
    }
}

int main() {
    fast_io();
    int r0, c0, r1, c1; cin >> r0 >> c0 >> r1 >> c1;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, seg_start, seg_end; cin >> r >> seg_start >> seg_end;
        for (int c = seg_start; c <= seg_end; c++) {
            V.insert({{r, c}, false});
        }
    }
    dist.insert({{r0, c0}, 0});
    bfs(r0, c0, r1, c1);
    if (dist.find({r1, c1}) != dist.end()) {
        cout << dist[{r1, c1}] << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}