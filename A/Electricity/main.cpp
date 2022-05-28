#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    int n;
    int cur[4];
    int prev[4];
    int temp[4];
    int dim[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    while (true) {
        cin >> n;
        if (n == 0) break;
        int validDays = 0;
        ll result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> cur[j];
            }

            for (int j = 0; j < 4; j++) {
                temp[j] = cur[j];
            }

            bool leap = ((cur[2] % 4 == 0 && cur[2] % 100 != 0) || cur[2] % 400 == 0);

            if (i != 0) {
                if (cur[0] < prev[0]) {
                    int prevMon = cur[1] - 1;
                    cur[0] += (leap && prevMon == 2 ? 29 : dim[prevMon]);
                    cur[1]--;
                }
                int dd = cur[0] - prev[0];
                if (cur[1] < prev[1]) {
                    cur[1] += 12;
                    cur[2]--;
                }
                int dm = cur[1] - prev[1];
                int dy = cur[2] - prev[2];
                if (dd == 1 && dm == 0 && dy == 0) {
                    validDays++;
                    result += (cur[3] - prev[3]);
                }
            }

            for (int j = 0; j < 4; j++) {
                prev[j] = temp[j];
            }
        }

        cout << validDays << " " << result << "\n";
    }

    return 0;
}