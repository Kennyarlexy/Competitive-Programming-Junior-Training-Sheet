#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Customer {
    ll N; //number of people
    ll M; //money
    ll id;
};

struct Table {
    ll cap;
    ll id;
};

bool cmp1(Customer A, Customer B) {
    return (A.N < B.N);
}

bool cmp2(Table A, Table B) {
    return (A.cap < B.cap);
}

Customer C[1005];
Table T[1005];

bool served[1005];
ll res[1005];

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll N, M;
        cin >> N >> M;
        C[i] = {N, M, i};
    }

    ll k; cin >> k;
    for (ll i = 1; i <= k; i++) {
        ll cap; cin >> cap;
        T[i] = {cap, i};
    }

    sort(C + 1, C + n + 1, cmp1);
    sort(T + 1, T + k + 1, cmp2);

    ll total = 0;
    ll cnt = 0;
    for (ll i = 1; i <= k; i++) {
        ll best = 0;
        ll bestid = 0;
        for (ll j = 1; j <= n; j++) {
            if (C[j].N > T[i].cap) break;
            if (served[C[j].id]) continue;
            if (C[j].M > best) {
                best = C[j].M;
                bestid = C[j].id;
            }
        }

        if (best > 0) {
            total += best;
            cnt++;
            res[bestid] = T[i].id;
            served[bestid] = true;
        }
    }

    cout << cnt << " " << total << "\n";
    for (ll id = 1; id <= n; id++) {
        if (!served[id]) continue;
        cout << id << " " << res[id] << "\n";
    }

    return 0;
}