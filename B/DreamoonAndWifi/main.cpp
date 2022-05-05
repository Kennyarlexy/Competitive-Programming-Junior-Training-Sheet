#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    string s1, s2; cin >> s1 >> s2;
    int len = s1.length();
    int countPos_s1 = 0, countPos_s2 = 0, countNeg_s1 = 0, countNeg_s2 = 0, countUnknown = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] == '+') countPos_s1++;
        else countNeg_s1++;
        
        if (s2[i] == '+') countPos_s2++;
        else if (s2[i] == '?') countUnknown++;
        else countNeg_s2++;
    }

    int k = fmax(countPos_s1 - countPos_s2, countNeg_s1 - countNeg_s2), c = countUnknown - k;
    if (countUnknown < k) {
        cout << "0\n";
        return 0;
    }
    
    ll total = pow(2, countUnknown);
    ll possible = 1;

    for (int i = countUnknown; i > k; i--) {
        possible *= i;
        while (c >= 2 && possible % c == 0) {
            possible /= c;
            c--;
        }
    }
    double result = (double) possible / total;
    cout << fixed << setprecision(10) << result << "\n";

    return 0;
}