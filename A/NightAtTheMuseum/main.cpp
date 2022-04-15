#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string s; cin >> s;
    char current = 'a';
    int moves = 0;
    for (int i = 0; i < s.length(); i++) {
        char target = s[i];
        int difference = abs(target - current);
        if (difference > 12) {
            difference = 26 - difference;
        }
        moves += difference;
        current = target;
    }
    cout << moves << endl;

    return 0;
}