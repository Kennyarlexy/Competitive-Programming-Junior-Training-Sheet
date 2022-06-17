#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int X[100005];

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, C; cin >> N >> C;
        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }

        sort(X, X+N);

        int d = 1;
        int l = X[0], r = X[N-1];
        for (int step = (r-l+1)/(C-1) - 1; step >= 1; step/=2) {
            while (true) {
                int temp = d+step;
                bool OK = false;
                int cowPlaced = 1;
                int prev = X[0];
                for (int i = 1; i < N; i++) {
                    if (X[i] - prev >= temp) {
                        cowPlaced++;
                        prev = X[i];
                    }

                    if (cowPlaced == C) {
                        OK = true;
                        break;
                    }
                }
                if (!OK) break;
                d = temp;
            }
        }

        cout << d << "\n";
    }

    return 0;
}