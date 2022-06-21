#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> adj[55];
bool vis[55];
ll res = 1;

void bfs(int cur) {
    queue<int> Q;
    Q.push(cur);
    vis[cur] = true;
    while (!Q.empty()) {
        int C = Q.front(); Q.pop();
        res *= 2;
        for (auto& next : adj[C]) {
            if (vis[next]) continue;
            vis[next] = true;
            Q.push(next);
        }
    }

    res /= 2; 
}


int main() {
    fast_io();
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue; 
        bfs(i);
    }
    cout << res << "\n";

    return 0;
}