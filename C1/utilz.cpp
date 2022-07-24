#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

//MST, CHECK CONSTRAINTS, CHECK CONSTRAINTS, CHECK CONSTRAINTS, -------------------------------------------------------------
ll N, M;

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
vector<pair<ll, ll>> adj[100005];
bool vis[100005];

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

//Combinatorics--------------------------------------------------------------------------
//combination implementation
//be careful because some combinations are impossible, like C(1, 2); C(1, 5); C(99, 100); etc
ll C(ll n, ll r) {
    if (n < r) return 0;

    ll res = 1;
    ll k = n - r;
    ll d = 2;
    if (k < r) swap(k, r);
    for (ll x = n; x > k; x--) {
        res *= x;
        while (d <= r && res % d == 0) {
            res /= d;
            d++;
        }
    }

    return res;
}

//permutation implementation
ll P(ll n, ll r) {
    if (n < r) return 0;

    ll res = 1;
    ll k = n - r;
    for (ll x = n; x > k; x--) {
        res *= x;
    }

    return res;
}


//factorial implementation
ll F(ll x) {
    if (x == 0) return 1;
    ll res = 1;
    for (ll k = x; k >= 2; k--) {
        res *= k;
    }
    
    return res;
}

//modular exponentiation implementation
ll modexp(ll X, ll exp, ll mod = 1000000007) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = (temp * temp) % mod;
    if (exp % 2 == 1) res = (res * X) % mod;

    return res;
}

int main() {
    fast_io();
    //use ll when possible!
    ll test = P(5, 5);

    cout << test << "\n";

    return 0;
}