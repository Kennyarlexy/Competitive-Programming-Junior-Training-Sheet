#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int D[35]; 
ll moves = 0;
bool valid = true;

void hanoi(int N, int from, int to, int temp) {
    if (N == 0 || !valid) return;

    if (D[N] == to) {
        moves += pow(2, N-1);
        hanoi(N-1, temp, to, from);
    } else if (D[N] == from) {
        hanoi(N-1, from, temp, to);
    } else {
        valid = false;
    }
}


int main() {
    fast_io();
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }
    hanoi(N, 1, 2, 3);

    if (valid) cout << moves << "\n";
    else cout << "-1\n";
    // cout << moves << "\n";

    return 0;
}