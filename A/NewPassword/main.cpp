#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int repeat = n - k;
    char ch = 'a';
    string password = "";
    for (int i = 0; i < n; i++) {
        password += (ch + (i % k));
    }
    
    cout << password << "\n";
    
    return 0;
}