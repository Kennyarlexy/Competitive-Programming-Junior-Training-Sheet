#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string A, B; cin >> A >> B;
    ll num_weight = A.length() - 1 + B.length();
    ll balance = num_weight / 2;
    ll middle = A.find('|');

    if (num_weight % 2 != 0 || fmin(middle, A.length() - (middle + 1)) + B.length() < balance) {
        cout << "Impossible\n";
    } else {
        ll insert_left = (middle < balance ? balance - middle : 0);
        ll insert_right = B.length() - insert_left;

        cout << A.substr(0, middle);
        cout << B.substr(0, insert_left);
        cout << A.substr(middle, A.length() - middle);
        cout << B.substr(insert_left, insert_right);
        cout << "\n";
    }
    
    return 0;
}