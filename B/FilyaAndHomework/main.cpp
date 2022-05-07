#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int n; cin >> n;
    set<int> nums;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        nums.insert(num);
    }

    if (nums.size() <= 2) {
        cout << "YES\n";
    } else if (nums.size() == 3) {
        int temp[3];
        int i = 0;
        for (auto& data : nums) {
            temp[i] = data;
            i++;
        }
        if ((temp[2] - temp[0]) % 2 == 0 && (temp[2] + temp[0]) / 2 == temp[1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}