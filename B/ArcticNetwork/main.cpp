#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll S, P;
ll x[505];
ll y[505];
bool sat[505];
bool vis[505];

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
vector<Edge> res;

ll d(ll u, ll v) {
    ll distance = (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]);
    return distance;
}

void addE(ll u) {
    for (ll v = 1; v <= P; v++) {
        if (vis[v]) continue;
        PQ.emplace(u, v, d(u, v));
    }
}

void mst(ll u) {
    vis[u] = true;
    addE(u);
    ll E = 0;
    ll ME = P - 1;
    while (!PQ.empty() && E < ME) {
        Edge e = PQ.top(); PQ.pop();
        if (vis[e.to]) continue;

        E++;
        res.push_back(e);
        vis[e.to] = true;
        addE(e.to);
    }
}

bool cmp(Edge A, Edge B) {
    return (A.cost < B.cost);
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(sat, 0, sizeof(sat));
        memset(vis, 0, sizeof(vis));
        PQ = priority_queue<Edge, vector<Edge>, Compare> ();
        res = vector<Edge> ();
        cin >> S >> P;
        for (ll u = 1; u <= P; u++) {
            cin >> x[u] >> y[u];
        }

        mst(1);
        sort(res.begin(), res.end(), cmp);

        ll cnt = 0;
        for (ll i = 0; i < res.size(); i++) {
            cnt++;
            if (cnt == P - S) {
                double D = sqrt(res[i].cost);
                cout << fixed << setprecision(2) << D << "\n";
                break;
            }
        }
    }

    return 0;
}