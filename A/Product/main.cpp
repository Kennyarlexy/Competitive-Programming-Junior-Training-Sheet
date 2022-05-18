#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    string x, y;
    while (cin >> x >> y) {
        if (x == "0" || y == "0") {
            cout << "0" << endl;
            continue;
        }
        int n = y.length();
        vector<string> row;

        string temp(251, '0');
        for (int yi = y.length() - 1; yi >= 0; yi--) {
            int prev = 0;
            int tempi = 250;
            for (int xi = x.length() - 1; xi >= 0; xi--) {
                int current = (x[xi] - '0') * (y[yi] - '0');
                current += prev / 10;
                temp[tempi] = (current % 10) + '0';
                prev = current;
                tempi--;
            }
            if (prev > 0) temp[tempi] = (prev / 10) + '0';
            row.push_back(temp);
        }

        string result(505, '0');
        for (int r = 0; r < n; r++) {
            int prev = 0;
            int resulti = 504 - r;
            for (int j = 250; j >= 0; j--) {
                int current = (result[resulti] - '0') + (row[r][j] - '0');
                current += prev / 10;
                result[resulti] = (current % 10) + '0';
                prev = current;
                resulti--;
            }
            result[resulti] = prev / 10 + '0';
        }

        for (int i = 0; i < 505; i++) {
            if (result[i] != '0') {
                cout << result.substr(i) << endl;
                break;
            }
        }
    }

    return 0;
}