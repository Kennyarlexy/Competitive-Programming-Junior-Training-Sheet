#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    cout << "INTERSECTING LINES OUTPUT\n";
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        long double x0a, y0a, x1a, y1a, 
            x0b, y0b, x1b, y1b;
        cin >> x0a >> y0a >> x1a >> y1a
            >> x0b >> y0b >> x1b >> y1b;
    
        long double ma = (y1a - y0a) / (x1a - x0a);
        long double mb = (y1b - y0b) / (x1b - x0b);

        if (isinf(ma) && isinf(mb)) {
            cout << (x0a == x0b ? "LINE" : "NONE") << "\n";
        } else if (isinf(ma)) {
            long double x = x0a;
            long double y = mb*(x0a - x0b) + y0b;
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << "\n";
        } else if (isinf(mb)) {
            long double x = x0b;
            long double y = ma*(x0a - x0a) + y0a;
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << "\n";
        } else {
            long double D = mb - ma;
            long double Dx = (mb*x0b - y0b) - (ma*x0a - y0a);
            long double Dy = ma*(mb*x0b - y0b) - mb*(ma*x0a - y0a);

            if (D == 0) D = 0;
            if (Dx == 0) Dx = 0;
            if (Dy == 0) Dy = 0;

            if (D == 0) {
                if (Dx == 0 && Dy == 0) cout << "LINE\n";
                else cout << "NONE\n";
            } else {
                long double x = Dx / D;
                long double y = Dy / D;
                cout << "POINT " << fixed << setprecision(2) << x << " " << y << "\n";
            }
        }
    }
    cout << "END OF OUTPUT\n";

    return 0;
}