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
	void multiply(ll F[2][2], ll M[2][2]);
	void power(ll F[2][2], ll n);

	ll mod = 1e9+7;

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
	}

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
        if (x == 0) return 1;
        ll res = 1;
        for (ll k = x; k >= 2; k--) {
            res *= k;
        }
        return res;
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
    vector<ll> adj[1005];
    bool vis[1005];
    bool vis1[1005];
    bool vis2[1005];

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