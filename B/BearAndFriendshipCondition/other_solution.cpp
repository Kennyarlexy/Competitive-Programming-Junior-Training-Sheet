#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vector<int> adj[150005];
bool vis[150005];

bool bfs(int start) {
    queue<int> Q;
    Q.push(start);
    vis[start] = true;

    ll E = adj[start].size();
    ll V = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        V++;
        if (adj[cur].size() != E) {
            return false;
        }
        for (auto& next : adj[cur]) {
            if (vis[next]) continue;
            vis[next] = true;
            Q.push(next);
        }
    }

    return (E == (V-1));
}

int main() {
    fast_io();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool OK = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (!bfs(i)) {
            OK = false;
            break;
        }
    }

    cout << (OK ? "YES" : "NO") << "\n";

    return 0;
}