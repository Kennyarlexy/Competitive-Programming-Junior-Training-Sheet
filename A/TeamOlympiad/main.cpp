#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> one;
    vector<int> two;
    vector<int> three;
    vector<int> count(3, 0);
    for (int i = 1; i <= n; i++) {
        int input; cin >> input;
        if (input == 1) {
            one.push_back(i);
            count[0]++;
        } else if (input == 2) {
            two.push_back(i);
            count[1]++;
        } else {
            three.push_back(i);
            count[2]++;
        }
    }

    sort(count.begin(), count.end());
    int team = count[0];
    cout << team << "\n";
    for (int i = 0; i < team; i++) {
        cout << one[i] << " " << two[i] << " " << three[i] << "\n";
    }
    
    return 0;
}