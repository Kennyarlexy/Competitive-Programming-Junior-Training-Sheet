#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, d; cin >> n >> b >> d;
    int total = 0, count = 0;
    for (int i = 0; i < n; i++) {
        int size; cin >> size;
        if (size <= b) {
            total += size;
        }
        if (total > d) {
            count++;
            total = 0;
        }
    }
    cout << count << "\n";
    
    return 0;
}