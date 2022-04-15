#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n >> t;

    string result = "";
    if (t == 10 && n == 1) {
        result = "-1";
    } else {
        result += to_string(t);
        for (int i = 1; i <= n-2; i++) {
            result += "0";
        }
        if (t < 10 && n > 1) {
            result += to_string(t);
        }
    }
    cout << result << "\n";

    
    return 0;
}