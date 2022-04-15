#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    long long result = 0;
    for (int start_seq = 1; start_seq <= 5; start_seq++) {
        int y = (n % 5 >= start_seq ? n/5 + 1 : n/5);
        int x = (m + (start_seq % 5))/5;
        result += (long long)x*y;
    }
    cout << result << "\n";

    return 0;
}