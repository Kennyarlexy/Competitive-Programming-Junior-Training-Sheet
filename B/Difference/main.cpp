#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int job[505];
vector<int> adj1[505];
vector<int> adj2[505];
bool vis1[505];
bool vis2[505];

int bfs1(int start) {
    queue<int> Q;
    Q.push(start);
    int time = -job[start];
    vis1[start] = true;
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        time += job[current];
        for (auto& next : adj1[current]) {
            if (vis1[next]) continue;
            Q.push(next);
            vis1[next] = true;
        }
    }
    
    return time;
}

int bfs2(int start) {
    queue<int> Q;
    Q.push(start);
    int time = 0;
    vis2[start] = true;
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        time += job[current];
        for (auto& next : adj2[current]) {
            if (vis2[next]) continue;
            Q.push(next);
            vis2[next] = true;
        }
    }
    
    return time;
}


int main() {
    fast_io();
    int t = 0;
    while (true) {
        t++;
        fill(job, job + 505, 0);
        fill(adj1, adj1 + 505, vector<int> ());
        fill(adj2, adj2 + 505, vector<int> ());

        int v, e; cin >> v >> e;
        if (v == 0 && e == 0) break;
        ll total = 0;
        for (int i = 1; i <= v; i++) {
            cin >> job[i];
            total += job[i];
        }
        for (int i = 1; i <= e; i++) {
            int from, to; cin >> from >> to;
            adj1[from].push_back(to);
            adj2[to].push_back(from);
        }
        
        int q; cin >> q;
        cout << "Case #" << t << ":\n";
        for (int i = 1; i <= q; i++) {
            fill(vis1, vis1 + 505, false);
            fill(vis2, vis2 + 505, false);
            int N; cin >> N;
            int min = bfs1(N);
            int exclude = bfs2(N);
            int max = total - exclude;
            int diff = max - min;
            cout << diff << "\n";
        }
        cout << "\n";
    }
    

    return 0;
}