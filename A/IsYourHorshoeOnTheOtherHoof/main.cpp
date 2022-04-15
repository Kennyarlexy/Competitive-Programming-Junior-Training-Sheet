#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> set;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int input;
        cin >> input;
        if (set.find(input) == set.end()) {
            set.insert(input);
        } else {
            count++;
        }
    }
    cout << count << "\n";
    
    return 0;
}