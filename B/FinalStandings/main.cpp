#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int ID[150005];
pair<int, int> P[150005];

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second) {
        return (A.first < B.first);
    }
    return (A.second > B.second);
}

int main() {
    fast_io();
    //use ll when possible!
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        int M;
        cin >> ID[i] >> M;
        P[i] = {i, M};
    }

    sort(P, P + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << ID[P[i].first] << " " << P[i].second << "\n";
    }

    return 0;
}