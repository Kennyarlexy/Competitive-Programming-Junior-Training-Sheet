#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    double x, y;
    while (true) {
        cin >> x >> y;
        if (x == 1 && y == 1) break;
        double ml = 0, nl = 1, mr = 1, nr = 0;
        double target = x / y;
        string path;
        if (target < 1) {
            ml = 0, nl = 1;
            mr = 1, nr = 1;
            path += 'L';
        } else {
            ml = 1, nl = 1;
            mr - 1, nr = 0;
            path += 'R';
        }


        while (true) {
            double mc = ml + mr;
            double nc = nl + nr;

            double cur = mc / nc;
            if (mc == x && nc == y) break;
            else if (cur > target) {
                path += 'L';
                mr = mc;
                nr = nc;
            } else {
                path += 'R';
                ml = mc;
                nl = nc;
            }
        }

        cout << path << "\n";
    }

    return 0;
}