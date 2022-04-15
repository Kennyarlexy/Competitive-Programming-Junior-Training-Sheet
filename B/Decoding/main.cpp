#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    for (int i = n - 2; i >= 0; i-=2) {
        cout << str[i];
    }
    for (int i = (n % 2 == 0 ? 1 : 0); i < n; i+=2) {
        cout << str[i];
    }
    cout << "\n";

    return 0;
}