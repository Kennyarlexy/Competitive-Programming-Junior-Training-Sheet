#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string inputs[3];
    for (int i = 0; i < 3; i++) {
        cin >> inputs[i];
    }
    pair<int, char> p[] = {{0, 'A'}, {0, 'B'}, {0, 'C'}};

    for (auto& input : inputs) {
        if (input[1] == '>') {
            p[input[0] - 'A'].first++;
        } else {
            p[input[2] - 'A'].first++;
        }
    }
    sort(p, p + 3);
    if (p[2].first == 2) {
        for (auto& data : p) {
            cout << data.second;
        }
    } else {
        cout << "Impossible";
    }
    cout << "\n";


    return 0;
}