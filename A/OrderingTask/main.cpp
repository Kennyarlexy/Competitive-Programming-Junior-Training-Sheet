#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> adj[105];
bool vis[105];
vector<int> O;

void topSort(int current) {
    vis[current] = true;
    for (auto& next : adj[current]) {
        if (vis[next]) continue;
        topSort(next);
    }

    O.push_back(current);
}

int main() {
    fast_io();
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        memset(vis, 0, sizeof(vis));
        fill(adj, adj+105, vector<int> ());
        O = vector<int> ();

        for (int i = 1; i <= m; i++) {
            int from, to; cin >> from >> to;
            adj[to].push_back(from);
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            topSort(i);
        }

        for (auto& data : O) {
            cout << data << " ";
        }

        cout << "\n";
    }

    return 0;
}