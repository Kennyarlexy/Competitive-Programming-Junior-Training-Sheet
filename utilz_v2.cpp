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
    //modular exponentiation implementation
    ll modexp(ll X, ll exp, ll mod = 1000000007) {
        if (exp == 0) return 1;
        ll root = modexp(X, exp/2, mod);
        ll res = (root * root) % mod;
        if (exp % 2 == 1) res = (res * X) % mod;
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

    //fibonacci: 0, 1, 2, 3, 5, ...
    ll fib(ll n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        ll a = 0, b = 1, c;
        for (ll i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    void construct_fib(ll A[], ll size) {
        A[0] = 0, A[1] = 1;
        for (ll i = 2; i <= size; i++) {
            A[i] = A[i-2] + A[i-1];
        }
    }

    void construct_sieve(bool A[], ll size) {
        A[0] = A[1] = true;
        for (ll i = 2; i <= size; i++) {
            if (A[i]) continue;
            for (ll j = 2*i; j <= size; j+=i) {
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
};

namespace geometry {
    struct Point
    {
        int x;
        int y;
    };
    
    // Given three collinear points p, q, r, the function checks if
    // point q lies on line segment 'pr'
    bool onSegment(Point p, Point q, Point r)
    {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    
        return false;
    }
    
    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are collinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    int orientation(Point p, Point q, Point r)
    {
        // for details of below formula.
        int val = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);
    
        if (val == 0) return 0;  // collinear
    
        return (val > 0)? 1: 2; // clock or counterclock wise
    }
    
    // The main function that returns true if line segment 'p1q1'
    // and 'p2q2' intersect.
    bool doIntersect(Point p1, Point q1, Point p2, Point q2)
    {
        // Find the four orientations needed for general and
        // special cases
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);
    
        // General case
        if (o1 != o2 && o3 != o4)
            return true;
    
        // Special Cases
        // p1, q1 and p2 are collinear and p2 lies on segment p1q1
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    
        // p1, q1 and q2 are collinear and q2 lies on segment p1q1
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    
        // p2, q2 and p1 are collinear and p1 lies on segment p2q2
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    
        // p2, q2 and q1 are collinear and q1 lies on segment p2q2
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    
        return false; // Doesn't fall in any of the above cases
    }
};

    
namespace graph_theory {
    vector<ll> adj[100005];
    bool vis[100005];

    void dfs(ll u) {
        if (vis[u]) return;

        vis[u] = true;
        for (auto& v : adj[u]) {
            dfs(v);
        }
    }

    void bfs(ll u) {
        queue<ll> Q; Q.push(u);
        vis[u] = true;

        while (!Q.empty()) {
            ll v = Q.front(); Q.pop();
            if (vis[v]) continue;
            Q.push(v);
            vis[v] = true;
        }
    }
};


int main() {
    fast_io();
    // use ll when possible!
    // using namespace combinatorics;
    // using namespace sequence_series;
    // using namespace num_theory;
    // using namespace geometry;
    // using namespace graph_theory;

    return 0;
}

/*
 * fast expo
 * modular inverse
 * __gcd
 * union find <<<<<< paling sering keluar di gemastik
 * BIT (binary indexed tree)/fenwick tree, or segment tree (+ lazy prop.)
 * shortest path (dijkstra, floyd-warshall (-ve cycle))
 * dp classical (2d sum, kadane, knapsack (w gede))
 * fast prime generator (sieve)
 * FFT
 * KMP
 * catalan numbers
 * The Inclusion-Exclusion Principle
 * 0-1 BFS
*/
