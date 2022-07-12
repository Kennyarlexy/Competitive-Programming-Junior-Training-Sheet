#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll M, N;
map<string, ll> city;

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

struct cmp {
    bool operator () (Edge A, Edge B) {
        return B.cost < A.cost;
    }
};

priority_queue<Edge, vector<Edge>, cmp> PQ;
vector<pair<ll, ll>> adj[2005];
bool vis[2005];

void addE(ll u) {
    for (auto& v : adj[u]) {
        if (vis[v.first]) continue;
        PQ.emplace(u, v.first, v.second);
    }
}

ll mst(ll u) {
    vis[u] = true;
    addE(u);
    ll E = 0;
    ll EM = M-1;
    ll total = 0;
    while (!PQ.empty() && E < EM) {
        Edge e = PQ.top(); PQ.pop();
        if (vis[e.to]) continue;

        E++;
        vis[e.to] = true;
        total += e.cost;
        addE(e.to);
    }

    return total;
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        city = map<string, ll> ();
        PQ = priority_queue<Edge, vector<Edge>, cmp> ();
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        cin >> M >> N;
        ll id = 0;
        for (ll E = 1; E <= N; E++) {
            string A, B; ll C;
            cin >> A >> B >> C;
            map<string, ll>::iterator it1, it2;
            bool in1, in2;
            tie(it1, in1) = city.emplace(A, id);
            tie(it2, in2) = city.emplace(B, id);
            if (in1) it1->second = ++id;
            if (in2) it2->second = ++id;
            adj[it1->second].emplace_back(it2->second, C);
            adj[it2->second].emplace_back(it1->second, C);
        }

        ll res = mst(1);
        cout << res << "\n";
        if (t < T) cout << "\n";
    }

    return 0;
}