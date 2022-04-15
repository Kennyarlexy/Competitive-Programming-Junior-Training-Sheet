#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B; cin >> A >> B;
    int result;
    if (A.length() > B.length()) {
        result = A.length();
    } else if (A.length() < B.length()) {
        result = B.length();
    } else {
        if (A == B) {
            result = -1;
        } else {
            result = A.length();
        }
    }
    cout << result << "\n";
    
    return 0;
}