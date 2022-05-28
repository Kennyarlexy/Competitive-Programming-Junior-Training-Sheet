#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool vis1[105];
bool vis2[105];
bool color[105];
vector<int> adj[105];

int nob = 0;

void dfs(int cur, bool c) {
    vis1[cur] = true;
    vis2[cur] = true;
    color[cur] = c;

    for (auto& next : adj[cur]) {
        if (vis1[next]) {
            if (vis2[next] && color[next] == color[cur]) nob++;
            continue;
        }
        dfs(next, !c);
    }

    vis2[cur] = false;
}

int main() {
    fast_io();
    int total, edge; cin >> total >> edge;

    for (int i = 1; i <= edge; i++) {
        int from, to; cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i <= edge; i++) {
        if (vis1[i]) continue;
        dfs(i, false);
    }

    int res = nob + (total - nob) % 2;
    // cout << nob << " nob\n";
    cout << res << "\n";

    return 0;
}