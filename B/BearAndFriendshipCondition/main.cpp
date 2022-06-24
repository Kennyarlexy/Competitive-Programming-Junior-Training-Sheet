#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
set<int> adj[150005];
bool vis[150005];

bool bfs(int start) {
    queue<int> Q;
    Q.push(start);
    vis[start] = true;

    ll V = 0;
    ll E = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        V++;
        vector<int> N;
        for (auto& next : adj[cur]) {
            N.push_back(next);
        }
        for (auto& next : N) {
            E++;
            adj[cur].erase(next);
            adj[next].erase(cur);
            if (vis[next]) continue;
            vis[next] = true;
            Q.push(next);
        }
    }

    ll check = V*(V-1) / 2;
    return (E == check);
}

int main() {
    fast_io();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
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