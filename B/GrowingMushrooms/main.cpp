#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool cmp(pair<int, double> PP1, pair<int, double> PP2) {
    if (PP1.second == PP2.second) {
        return (PP1.first < PP2.first);
    }
    return (PP1.second > PP2.second);
}

int main() {
    fast_io();
    int n, t1, t2, k; cin >> n >> t1 >> t2 >> k;
    pair<int, double> PP[n];
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        double pos1 = (double) a*t1*(100-k)/100 + b*t2;
        double pos2 = (double) b*t1*(100-k)/100 + a*t2;
        double max = fmax(pos1, pos2);
        PP[i] = make_pair(i+1, max);
    }
    sort(PP, PP + n, cmp);

    for (auto& data : PP) {
        cout << fixed << setprecision(2) << data.first << " " << data.second << "\n";
    }

    return 0;
}