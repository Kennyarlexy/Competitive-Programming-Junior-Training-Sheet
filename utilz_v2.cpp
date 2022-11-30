#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

namespace combinatorics {
    //combination implementation
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
};

namespace sequence_series {
    ll Un(ll n, ll a, ll b) {
        ll res = a + (n - 1)*b;
        return res;
    }

    ll Sn(ll n, ll a, ll b) {
        ll res = n * (2*a + (n - 1)*b) / 2;
        return res;
    }
};

namespace num_theory {
    ll mod = 1e9+7;
    void multiply(ll F[2][2], ll M[2][2]);
    void power(ll F[2][2], ll n);


    ll fib(ll n){
        ll F[2][2] = {{1, 1}, {1, 0}};
        if (n == 0) return 0;
        power(F, n - 1);
        return F[0][0];
    }

    void power(ll F[2][2], ll n){
        if(n == 0 || n == 1) return;
        ll M[2][2] = {{1, 1}, {1, 0}};
    
        power(F, n / 2); multiply(F, F);
        if (n % 2 != 0) multiply(F, M);
    }

    void multiply(ll F[2][2], ll M[2][2]){
        ll x = ((F[0][0] % mod * M[0][0] % mod) + (F[0][1] * M[1][0] % mod)) % mod;
        ll y = ((F[0][0] % mod * M[0][1] % mod) + (F[0][1] * M[1][1] % mod)) % mod;
        ll z = ((F[1][0] % mod * M[0][0] % mod) + (F[1][1] * M[1][0] % mod)) % mod;
        ll w = ((F[1][0] % mod * M[0][1] % mod) + (F[1][1] % mod * M[1][1] % mod)) % mod;
    
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    } // above code is a part of fast_fibo
    
    
    ll modInverse(ll A, ll M){
        ll m0 = M;
        ll y = 0, x = 1;        
        if (M == 1) return 0;
        while (A > 1) {
            ll q = A / M;
            ll t = M;
            M = A % M, A = t;
            t = y;
            y = x - q * y;
            x = t;
        }

        if (x < 0) x += m0;
        return x;
    }
    
    //modular exponentiation implementation
    ll modexp(ll X, ll exp, ll mod = 1000000007) {
        if (exp == 0) return 1;
        ll root = modexp(X, exp/2, mod);
        ll res = (root * root) % mod;
        if (exp & 1) res = (res * X) % mod;
        return res;
    }

    //factorial implementation
    ll F(ll x) {
        // beware of overflow
        if (x == 0) return 1;
        ll res = 1;
        for (ll k = x; k >= 2; k--) {
            res *= k;
        }
        return res;
    }

    void construct_fib(ll A[], ll size) {
        // cuman bisa sampai fib ke-93
        A[0] = 0, A[1] = 1;
        for (ll i = 2; i <= size; i++) {
            A[i] = A[i-2] + A[i-1];
        }
    }

    void construct_sieve(bool A[], ll size) {
        A[0] = A[1] = true;
        for (ll i = 2; i <= size; i++) {
            if (A[i]) continue;
            for (ll j = i*i; j <= size; j+=i) {
                A[j] = true;
            }
        }
    }

    bool isPrime(ll X) {
        if (X <= 1) return false;
        for (ll i = 2; i*i <= X; i++) {
            if (X % i == 0) return false;
        }
        return true;
    }

    bool isPerfectSquare(ll X) {
        ll root = sqrt(X);
        return root*root == X;
    }
    
    ll phi(ll n){
        ll result = n;
        for(ll p = 2; p * p <= n; ++p){
            if (n % p == 0){
                while (n % p == 0) n /= p;
                result -= result / p;
            }
        }
        if (n > 1) result -= result / n;	
        return result;
    }

    vector<ll> Phi(100000);
    void phi_1_to_n(ll n) {
    for (ll i = 0; i <= n; i++) Phi[i] = i;
        for (ll i = 2; i <= n; i++) {
            if (Phi[i] == i) {
                for (ll j = i; j <= n; j += i)
                    Phi[j] -= Phi[j] / i;
            }
        }
    }

    ll largestDivPow2(ll x) {
        return x & -x;
    }

    ll gcd(ll A, ll B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }

    ll lcm(ll A, ll B) {
        return A / __gcd(A, B) * B;
    }
};

namespace geometry {
    struct Point
    {
        ll x;
        ll y;
    };
    
    bool onSegment(Point p, Point q, Point r) {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
        
        return false;
    }
    
    ll orientation(Point p, Point q, Point r){
        
        ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        
        if (val == 0) return 0;
        
        return (val > 0)? 1: 2;
    }
    
    bool doIntersect(Point p1, Point q1, Point p2, Point q2){
        ll o1 = orientation(p1, q1, p2);
        ll o2 = orientation(p1, q1, q2);
        ll o3 = orientation(p2, q2, p1);
        ll o4 = orientation(p2, q2, q1);
        
        if (o1 != o2 && o3 != o4) return true;
        
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;

        if (o4 == 0 && onSegment(p2, q1, q2)) return true;
        
        return false;
    }
};

namespace bitmask {
    // index of the least significant bit from the right, x > 0
    ll LSOne(ll x) {
        return __builtin_ctzll(x);
    }

    // index of the most significant bit from the right, x > 0
    ll MSOne(ll x) {
        return 63 - __builtin_clzll(x);
    }
};

namespace generator {
    // generate all 2^size subset, returns true if we can make a subset that sums to target
    // A[] zero indexed, if one indexed -> subset(A + 1, size, target)
    bool subset(ll A[], ll size, ll target) {
        for (ll i = 1; i < (1<<size); i++) {
            ll sum = 0;
            ll mask = i;
            while (mask > 0) {
                ll j = __builtin_ctzll(mask);
                sum += A[j];
                mask ^= (1 << j);
            }
            if (sum == target) return true;
        }
        return false;
    }

    // bruteforce C(n, k) without writing nested for loops
    // A[] zero indexed, if one indexed -> subset(A + 1, k, n)
    void bruteforce(ll A[], ll k, ll n) {
        vector<ll> take;
        take.resize(n-k, 0); take.resize(n, 1);
        do {
            for (ll i = 0; i < n; i++) {
                if (take[i]) {
                    // do something with A[i];
                }
            }
            // check for something
        } while (next_permutation(take.begin(), take.end()));
    }
};

namespace graph_theory {
    ll N;
    vector<ll> adj[300005];
    bool vis[300005];
    //for cycle detection
    bool vis1[300005];
    bool vis2[300005];
    //for union find
    ll link[300005];
    ll size[300005];
    //for 0-1 BFS
    ll dist[300005];
    //for flood fill;
    char grid[1005][1005];
    bool visff[1005][1005];

    //for dijkstra and MST -> Edge, cmp, adjE, PQ
    //Edge may also contain from
    struct Edge {
        ll to;
        ll cost;
        Edge(ll _to, ll _cost) {
            to = _to;
            cost = _cost;
        }
    };
    
    struct cmp {
        bool operator () (Edge A, Edge B) {
            return A.cost > B.cost;
        }
    };

    vector<Edge> adjE[300005];
    priority_queue<Edge, vector<Edge>, cmp> PQ; //minimum priority queue


    void dfs(ll u) {
        if (vis[u]) return;

        vis[u] = true;
        for (auto& v : adj[u]) {
            dfs(v);
        }
    }

    void bfs(ll s) {
        queue<ll> Q; Q.push(s);
        vis[s] = true;

        while (!Q.empty()) {
            ll u = Q.front(); Q.pop();
            for (auto& v : adj[u]) {
                // add more constraint when needed
                if (vis[v]) continue;
                Q.push(v);
                vis[v] = true;
            }
        }
    }

    bool isCyclic(ll u) {
        if (vis1[u]) return vis2[u];

        vis1[u] = true;
        vis2[u] = true;
        bool cyclic = false;
        for (auto& v : adj[u]) {
            if (isCyclic(v)) {
                cyclic = true;
                break;
            }
        }
        vis2[u] = false;
        return cyclic;
    }

    // Union Find -> find(), same(), unite()
    // returns the representative of u
    ll find(ll u) {
        while (link[u] != u) u = link[u];
        return u;
    }

    // returns true if u and v belong to the same set (have the same representative)
    bool same(ll u, ll v) {
        return find(u) == find(v);
    }

    // combine set u and v where size[u] > size[v] with u as the new representative 
    void unite(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (size[u] < size[v]) swap(u, v);
        link[v] = u;
        size[u] += size[v];
    }

    // calculate distance from s to all other nodes
    void bfs01(ll s) {
        queue<ll> Q; Q.push(s);
        vis[s] = true;
        dist[s] = 0;

        while (!Q.empty()) {
            ll u = Q.front(); Q.pop();
            for (auto& v : adj[u]) {
                // add more constraint when needed
                if (vis[v]) continue;
                Q.push(v);
                vis[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }

    void flood_fill_4(ll sr, ll sc) {
        queue<ll> Qr; Qr.push(sr);
        queue<ll> Qc; Qc.push(sc);
        visff[sr][sc] = true;

        ll dr[] = {1, 0, -1, 0};
        ll dc[] = {0, 1, 0, -1};
        while (!Qr.empty()) {
            ll cr = Qr.front(); Qr.pop();
            ll cc = Qc.front(); Qc.pop();
            for (ll i = 0; i < 4; i++) {
                ll nr = cr + dr[i];
                ll nc = cc + dc[i];
                // constraint > 0
                if (visff[nr][nc]) continue;

                Qr.push(nr);
                Qc.push(nc);
                visff[nr][nc] = true;
            }
        }
    }

    void flood_fill_8(ll sr, ll sc) {
        queue<ll> Qr; Qr.push(sr);
        queue<ll> Qc; Qc.push(sc);
        visff[sr][sc] = true;

        ll dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
        ll dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        while (!Qr.empty()) {
            ll cr = Qr.front(); Qr.pop();
            ll cc = Qc.front(); Qc.pop();
            for (ll i = 0; i < 4; i++) {
                ll nr = cr + dr[i];
                ll nc = cc + dc[i];
                // constraint > 0
                if (visff[nr][nc]) continue;

                Qr.push(nr);
                Qc.push(nc);
                visff[nr][nc] = true;
            }
        }
    }


    void dijkstra(ll start) {
        //need create priority_queue in ascending order, declare as global
        //initially, set dist[u] for every u to INFINITY
        PQ.emplace(start, 0);
        dist[start] = 0;
        
        while (!PQ.empty()) {
            ll current, prevMin;
            Edge e = PQ.top(); PQ.pop();
            vis[e.to] = true;
            // e.cost here is cumulative edge cost from node start
            if (dist[e.to] < e.cost) continue; //is e.cost outdated?

            for (auto& ne : adjE[e.to]) {
                if (vis[ne.to]) continue;
                dist[ne.to] = min(dist[ne.to], e.cost + ne.cost);
                PQ.emplace(ne.to, dist[ne.to]);
            }
        }
    }

    void addE(ll u) {
        for (auto& [to, cost] : adjE[u]) {
            if (vis[to]) continue;
            PQ.emplace(to, cost);
        }
    }

    // returns the MST's total edge weight
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
            vis[e.to] = true;
            addE(e.to);
        }

        if (E == ME) return total;
        else return -1;
    }
};

namespace algo_string {
    string s;
    bool isPalindrome(ll l, ll r) {
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};

int main() {
    fast_io();
    // use ll when possible!
    // using namespace combinatorics;
    // using namespace sequence_series;
    // using namespace num_theory;
    // using namespace geometry;
    // using namespace bitmask;
    // using namespace generator;
    // using namespace graph_theory;
    // using namespace algo_string;
    
    return 0;
}

/*
 * fast expo
 * modular inverse DONE
 * fast prime generator (sieve) DONE
 * union find <<<<<< paling sering keluar di gemastik DONE
 * shortest path (dijkstra, floyd-warshall (-ve cycle))
 * dp classical (kadane, knapsack (w gede))
 * 0-1 BFS DONE
 * catalan numbers

yg dibawah ini aku gatau kegunaannya + cara makenya :v
 * FFT
 * KMP
 * The Inclusion-Exclusion Principle
 * BIT (binary indexed tree)/fenwick tree, or segment tree (+ lazy prop.)
*/