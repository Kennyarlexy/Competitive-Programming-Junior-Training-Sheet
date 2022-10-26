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

        int d = 0;
        int l = X[0], r = X[N-1];
        //increase the d, step by step using binary search technique
        for (int step = (X[N-1]-X[0]+1)/2; step >= 1; step/=2) {
            while (true) {
                int new_d = d+step; //let's try this new d, can all cows still fit?
                int cowPlaced = 1;
                int prev = X[0];
                for (int i = 1; i < N; i++) {
                    if (X[i] - prev >= new_d) {
                        cowPlaced++;
                        prev = X[i];
                        if (cowPlaced == C) break;
                    }
                }
                if (cowPlaced < C) break;
                d = new_d; //same with d += step, repeat the loop, attempt to increase the d but still with the same step
            }
        }

        cout << d << "\n";
    }

    return 0;
}