#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m, a, d; cin >> n >> m >> a >> d;
        int max = a + 4*d;
        int min = a; 
        int count = 0;

        for (int i = n; i <= m; i++) {
            bool divisible = false;
            for (int div = max; div >= min; div -= d) {
                if (i % div == 0) {
                    divisible = true;
                    break;
                }
            }
            if (!divisible) {
                count++;
            }
        }
        cout << count << "\n";
    }
    
    return 0;
}