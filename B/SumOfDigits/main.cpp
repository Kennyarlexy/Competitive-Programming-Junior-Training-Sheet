#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string n; cin >> n;
    int count = 0;
    while (n.length() > 1) {
        int sum = 0;
        for (auto& digit : n) {
            sum += digit - '0';
        }
        count++;
        n = to_string(sum);
    }
    cout << count << "\n";

    return 0;
}