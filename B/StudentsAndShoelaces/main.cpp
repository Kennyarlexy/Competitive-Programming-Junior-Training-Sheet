#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

set<int> adj[105];
queue<int> Q;
bool kicked[105];

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            Q.push(i);
            kicked[i] = true;
        }
    }

    int result = 0;
    queue<int> temp;
    while(!Q.empty()) {
        int current = Q.front();
        Q.pop();
        int next = *adj[current].begin();
        if (adj[current].find(next) != adj[current].end() && adj[next].find(current) != adj[next].end()) {
            adj[current].erase(next);
            adj[next].erase(current);
        }
        if (adj[next].size() == 1 && !kicked[*adj[next].begin()]) {
            temp.push(next);
            kicked[next] = true;
        }

        if (Q.empty()) {
            Q = temp;
            temp = queue<int>();
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}