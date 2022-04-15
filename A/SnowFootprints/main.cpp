#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    string path; cin >> path;
    int first_R = 0;
    int first_L = 0;
    int count_R = 0;
    int count_L = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == 'R') {
            if (first_R == 0) first_R = i+1;
            count_R++;
        } else if (path[i] == 'L') {
            if (first_L == 0) first_L = i+1;
            count_L++;
        }
    }

    int start = 0;
    int end = 0;
    if (first_L == 0) {
        start = first_R;
        end = start + count_R;
    } else if (first_R == 0) {
        start = first_L + count_L - 1;
        end = first_L - 1;
    } else {
        start = first_R;
        end = first_L - 1;
    }
    cout << start << " " << end << "\n";

    return 0;
}