#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int A = 1, B = n;
    bool result = true;
    char diagonal, rest;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch; cin >> ch;
            if (i == 1 && j == 1) diagonal = ch;
            if (i == 1 && j == 2) rest = ch;


            if (j == A || j == B) {
                if (ch != diagonal) result = false;
            } else {
                if (ch != rest || ch == diagonal) result = false;
            }
        }
        A++;
        B--;
    }
    if (result) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}