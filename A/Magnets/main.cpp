#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string left; cin >> left;
    int group = 1;
    for (int i = 0; i < n-1; i++) {
        string right; cin >> right;
        if (right != left) {
            group++;
            left = right;
        }
    }
    cout << group << endl;
    
    return 0;
}