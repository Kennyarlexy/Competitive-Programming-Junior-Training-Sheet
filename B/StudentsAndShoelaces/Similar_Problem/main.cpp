#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

set<int> adj[400005];
bool removed[400005];

int main() {
    fast_io();
    int t; cin >> t;
    for (int T = 1; T <= t; T++) {
        queue<int> Q;
        int n, k; cin >> n >> k;
        fill(adj, adj + n + 5, set<int>());
        fill(removed, removed + n + 5, false);
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        for (int i = 1; i <= n; i++) {
            if (adj[i].size() <= 1) Q.push(i);
        }

        int count = 0;
        queue<int> temp;
        while(!Q.empty() && count < k) {
            int current = Q.front();
            Q.pop();
            removed[current] = true;
            int next = *adj[current].begin();
            
            if (adj[current].find(next) != adj[current].end()) adj[current].erase(next);

            if (adj[next].find(current) != adj[next].end()) adj[next].erase(current);

            if (adj[next].size() == 1 && !removed[next]) temp.push(next);

            if (Q.empty()) {
                Q = temp;
                temp = queue<int> ();
                count++;
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!removed[i]) result++;
        }
        cout << result << "\n";
    }

    return 0;
}