#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool rated = false;
    bool non_asc = true;
    int prev_before, prev_after;
    for (int i = 1; i <= n; i++) {
        int before, after; cin >> before >> after;

        if (before != after) rated = true;
        if (i > 1) {
            if (before > prev_before) non_asc = false;
        }

        prev_before = before;
        prev_after = after;
    }

    if (rated) cout << "rated\n";
    else {
        if (non_asc) cout << "maybe\n";
        else cout << "unrated\n";
    }
    
    return 0;
}