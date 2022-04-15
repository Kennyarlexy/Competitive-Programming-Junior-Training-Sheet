#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string A, B;
    int count_A = 0, count_B = 0;
    bool bothScorses = false;
    // int curTeam = 0;
    for (int i = 1; i <= n; i++) {
        string temp; cin >> temp;
        if (i == 1) A = temp;

        if (temp == A) {
            count_A++;
        } else {
            if (!bothScorses) {
                B = temp;
                bothScorses = true;
            }
            count_B++;
        }
    
    if (!bothScorses) {
        cout << A << "\n";
    } else {
        if (count_A > count_B) cout << A << "\n";
        else cout << B << "\n";
    }
    
    return 0;
}