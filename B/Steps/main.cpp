#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n, m; cin >> n >> m;
    int sr, sc; cin >> sr >> sc;
    int k; cin >> k;
    queue<int> dir_r;
    queue<int> dir_c;
    for (int i = 1; i <= k; i++) {
        int dr, dc; cin >> dr >> dc;
        dir_r.push(dr);
        dir_c.push(dc);
    }

    ll steps = 0;
    int cr = sr, cc = sc;
    while (!dir_r.empty()) {
        int dr = dir_r.front();
        int dc = dir_c.front();
        dir_r.pop();
        dir_c.pop();

        int Dr = (dr > 0 ? n - cr : 1 - cr);
        int Dc = (dc > 0 ? m - cc : 1 - cc);
        int step_r = (dr == 0 ? INT_MAX : Dr / dr);
        int step_c = (dc == 0 ? INT_MAX : Dc / dc);

        int step = fmin(step_r, step_c);
        steps += step;

        cr += step * dr;
        cc += step * dc;
        
        // while (true) {
        //     int check_r = cr + dr;
        //     int check_c = cc + dc;
        //     if (check_r > n || check_c > m || check_r <= 0 || check_c <= 0) break;
        //     cr = check_r;
        //     cc = check_c;
        //     steps++;
        // }
    }
    cout << steps << "\n";

    return 0;
}