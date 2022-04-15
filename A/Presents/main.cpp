#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int giftfor[n];
    for (int i = 0; i < n; i++) {
        int receiver; cin >> receiver;
        giftfor[receiver-1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << giftfor[i] << " ";
    }
    cout << "\n";
    
    return 0;
}