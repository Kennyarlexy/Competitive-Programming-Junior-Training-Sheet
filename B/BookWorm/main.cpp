#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int thickness, cover, start, end; cin >> thickness >> cover >> start >> end;
    int result;
    if (end > start) {
        int travel = end - start - 1;
        result = 2*cover + (2*cover + thickness)*travel;
    } else if (end <= start) {
        int travel = start - end;
        result = thickness + (2*cover + thickness)*travel;
    }
    cout << result << "\n";

    return 0;
}