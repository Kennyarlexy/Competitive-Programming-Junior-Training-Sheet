#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    string move; cin >> move;
    int move_R = -1;
    int move_L = -1;

    int min = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (move[i] == 'R') move_R = x;
        else if (move[i] == 'L') move_L = x;

        if (move_L > move_R && move_L >= 0 && move_R >= 0) {
            int d = move_L - move_R;
            int time = d/2;
            if (min == -1 || time < min) min = time;
        }
    }
    cout << min << "\n";
    

    return 0;
}