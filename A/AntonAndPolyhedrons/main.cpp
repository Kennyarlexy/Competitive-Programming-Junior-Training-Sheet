#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sides = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (s == "Tetrahedron") sides += 4;
        if (s == "Cube") sides += 6;
        if (s == "Octahedron") sides += 8;
        if (s == "Dodecahedron") sides += 12;
        if (s == "Icosahedron") sides += 20;
    }
    cout << sides << "\n";
    
    return 0;
}