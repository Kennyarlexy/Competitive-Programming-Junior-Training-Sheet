#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    while (true) {
        pair<double, double> start;
        set<pair<double, double>> U;
        bool OK = true;
        for (int i = 1; i <= 4; i++) {
            double t1, t2;
            if (!(cin >> t1 >> t2)) {
                OK = false;
                break;
            }
            if (U.find({t1, t2}) != U.end()) {
                start = {t1, t2};
                U.erase({t1, t2});
            } else {
                U.insert({t1, t2});
            }
        }

        if (!OK) break;
        // cout << start.first << " " << start.second << "\n";

        pair<double, double> result = start;
        for (auto& p : U) {
            result.first += (p.first - start.first);
            result.second += (p.second - start.second);
        }

        cout << fixed << setprecision(3) << result.first << " " << result.second << "\n";
    }


    return 0;
}