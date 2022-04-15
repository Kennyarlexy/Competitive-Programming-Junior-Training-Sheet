#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string num; cin >> num;
    for (int i = 0; i < num.length(); i++) {
        if (num[i] >= '5') {
            if (i == 0 && num[i] == '9') continue;
            num[i] = '9' - (num[i] - '0');
        }
    }
    cout << num << "\n";

    return 0;
}