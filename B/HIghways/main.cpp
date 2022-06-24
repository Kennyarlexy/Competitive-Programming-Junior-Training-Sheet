#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll x[800];
ll y[800];
ll N, M;
ll k = 0;


struct Edge {
    ll from;
    ll to;
    ll len;

    Edge(ll f, ll t, ll l) {
        from = f;
        to = t;
        len = l;
    }
};

vector<ll> adj[800];
bool dfsvis[800];
vector<ll> comp[800];
ll compid[800];

void dfs(ll start) {
    dfsvis[start] = true;
    comp[k].push_back(start);
    compid[start] = k;
    for (auto& next : adj[start]) {
        if (dfsvis[next]) continue;
        dfs(next);
    }
}

ll d(ll u, ll v) {
    ll distance = (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]);
    return distance;
}

struct Compare {
    bool operator() (Edge A, Edge B) {
        return (B.len < A.len);
    }
};

priority_queue<Edge, vector<Edge>, Compare> PQ;
bool compvis[800];
vector<Edge> res;

void addE(ll id) {
    for (auto& u : comp[id]) { //all u in component with this id
        for (ll v = 1; v <= N; v++) {
            if (compvis[compid[v]] || compid[u] == compid[v]) continue;
            PQ.emplace(u, v, d(u, v));
        }
    }
}

void mst(ll start) {
    compvis[compid[start]] = true;
    addE(compid[start]);
    ll E = 0; //edge count
    ll ME = k-1; //max edge for tree (no cycle)
    while(!PQ.empty() && E < ME) {
        Edge e = PQ.top(); PQ.pop();
        if (compvis[compid[e.to]]) continue;

        E++;
        res.push_back(e);
        compvis[compid[e.to]] = true;
        addE(compid[e.to]);
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        memset(adj, 0, sizeof(adj));
        memset(dfsvis, 0, sizeof(dfsvis));
        memset(comp, 0, sizeof(comp));
        memset(compid, 0, sizeof(compid));
        memset(compvis, 0, sizeof(compvis));
        PQ = priority_queue<Edge, vector<Edge>, Compare> ();
        res = vector<Edge> ();
        cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> x[i] >> y[i];
        }

        ll M; cin >> M;
        for (ll i = 1; i <= M; i++) {
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        k = 0;
        for (ll i = 1; i <= N; i++) {
            if (dfsvis[i]) continue;
            k++;
            dfs(i);
        }
        
        if (k == 1) {
            cout << "No new highways need\n";
        } else {
            mst(1);
            for (auto& e : res) {
                cout << e.from << " " << e.to << "\n";
            }
        }

        if (t < T) cout << "\n";
    }

    return 0;
}