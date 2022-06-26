#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll N, M; 
vector<pair<ll, ll>> adj[105];

struct Edge {
    ll from;
    ll to;
    ll cost;
    Edge(ll f, ll t, ll c) {
        from = f;
        to = t;
        cost = c;
    }
};

struct Compare {
    bool operator() (Edge A, Edge B) {
        return (B.cost < A.cost);
    }
};

priority_queue<Edge, vector<Edge>, Compare> PQ;
bool vis[105];
ll du = 0, dv = 0; //deleted from, deleted to

void addE(ll u) {
    for (auto& v : adj[u]) {
        if (vis[v.first] || (u == du && v.first == dv) || (u == dv && v.first == du)) continue;
        PQ.emplace(u, v.first, v.second);
    }
}

vector<Edge> res;

ll mst(ll start, bool flag) {
    vis[start] = true;
    ll E = 0;
    ll ME = N - 1;
    ll total = 0;
    addE(start);
    while (!PQ.empty() && E < ME) {
        Edge e = PQ.top(); PQ.pop();
        if (vis[e.to]) continue;

        E++;
        total += e.cost;
        if (flag) {
            res.push_back(e);
        }
        vis[e.to] = true;
        addE(e.to);
    }

    if (E == ME) return total;
    else return -1;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        res = vector<Edge> ();
        PQ = priority_queue<Edge, vector<Edge>, Compare> ();
        du = 0; dv = 0;

        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }

        ll s1 = mst(1, true);
        ll s2 = LONG_LONG_MAX;
        for (auto& e : res) {
            du = e.from;
            dv = e.to;
            PQ = priority_queue<Edge, vector<Edge>, Compare> ();

            memset(vis, 0, sizeof(vis));
            ll temp = mst(1, false);
            if (temp != -1) s2 = min(s2, temp);
        }
        cout << s1 << " " << s2 << "\n";
    }

    return 0;
}