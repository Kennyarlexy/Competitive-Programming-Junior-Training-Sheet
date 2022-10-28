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
		if (x == 0) return 1;
		ll res = 1;
		for (ll k = x; k >= 2; k--) {
			res *= k;
			// remove above and add this if want to mod it by 1e9+7 bcs biggest fac that C++ long long can hold is 20!
			// res = ((res%mod) * (k%mod)) % mod; 
		}
		return res;
	}

	void construct_fib(ll A[], ll size) {
		A[0] = 0, A[1] = 1;
		for (ll i = 2; i <= size; i++) {
			A[i] = A[i-2] + A[i-1];
			// remove above and add this if want to mod it by 1e9+7 bcs biggest fibo that C++ long long can hold is F(93)
			// A[i] = ((A[i-2]%mod) + (A[i-1]%mod)) % mod;
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


namespace graph_theory {
	vector<ll> adj[300005];
	bool vis[300005];
	bool vis1[300005];
	bool vis2[300005];

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
 * modular inverse DONE
 * fast prime generator (sieve) DONE
 * union find <<<<<< paling sering keluar di gemastik 
 * shortest path (dijkstra, floyd-warshall (-ve cycle))
 * dp classical (kadane, knapsack (w gede))
 * 0-1 BFS
 * catalan numbers

yg dibawah ini aku gatau kegunaannya + cara makenya :v
 * FFT
 * KMP
 * The Inclusion-Exclusion Principle
 * BIT (binary indexed tree)/fenwick tree, or segment tree (+ lazy prop.)
*/