#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Edge {
    int to;
    int color = 0;
};

vector<Edge> adj[105];
bool vis[105];
bool used[105];

bool dfs(int cur, int target, Edge pe) {
    if (cur == target) {
        used[pe.color] = true;
        return true;
    }

    vis[cur] = true;
    bool found = false;
    for (auto& e : adj[cur]) {
        if (vis[e.to]) continue;
        if (e.color == pe.color) {
            if (dfs(e.to, target, e)) found = true;
            if (found) break;
        }
    }

    return found;
}

int main() {
    fast_io();
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        Edge edge;
        edge.to = b;
        edge.color = c;
        adj[a].push_back(edge);
        edge.to = a;
        adj[b].push_back(edge);
    }

    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int cnt = 0;
        int u, v; cin >> u >> v;
        memset(used, false, sizeof(used));
        for (auto& e : adj[u]) {
            if (used[e.color]) continue;
            memset(vis, false, sizeof(vis));
            vis[u] = true;
            if (dfs(e.to, v, e)) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}