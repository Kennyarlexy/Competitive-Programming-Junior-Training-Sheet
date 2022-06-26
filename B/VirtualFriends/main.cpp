#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll cnt[100005]; //member count for k-th comp
ll compid[100005];
map<string, ll> MP; //string to node id converter
vector<ll> adj[100005];
bool vis[100005];

void dfs(ll u, ll id) {
    vis[u] = true;
    compid[u] = id;
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        dfs(v, id);
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(cnt, 0, sizeof(cnt));
        memset(adj, 0, sizeof(adj));
        memset(compid, 0, sizeof(compid));
        MP = map<string, ll> ();
        ll F; cin >> F;
        ll k = 0; //node count
        ll c = 0; //comp count
        for (ll e = 1; e <= F; e++) {
            string a, b;
            cin >> a >> b;
            map<string, ll>::iterator it1, it2;
            bool in1, in2;
            tie(it1, in1) = MP.emplace(a, k);
            tie(it2, in2) = MP.emplace(b, k);
            ll &u = it1->second;
            ll &v = it2->second;
            if (in1) u = ++k;
            if (in2) v = ++k;
            adj[u].push_back(v);
            adj[v].push_back(u);

            if (in1 && in2) { //both new
                cnt[++c] += 2;
                compid[u] = compid[v] = c;
                cout << "2\n";
            } else if (in1) {
                compid[u] = compid[v];
                cnt[compid[u]]++;
                cout << cnt[compid[u]] << "\n";
            } else if (in2) {
                compid[v] = compid[u];
                cnt[compid[v]]++;
                cout << cnt[compid[v]] << "\n";
            } else if (compid[u] != compid[v]) {
                fill(vis, vis + k + 5, 0);
                if (cnt[compid[u]] > cnt[compid[v]]) {
                    cnt[compid[u]] += cnt[compid[v]];
                    dfs(v, compid[u]);
                    cout << cnt[compid[u]] << "\n";
                } else {
                    cnt[compid[v]] += cnt[compid[u]];
                    dfs(u, compid[v]);
                    cout << cnt[compid[v]] << "\n";
                }
            } else {
                cout << cnt[compid[u]] << "\n";
            }
        }
    }

    return 0;
}