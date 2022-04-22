#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N; cin >> N;
    for (int t = 1; t <= N; t++) {
        string a, b; cin >> a >> b;
        string result;
        int prevSum = 0;
        for (int i = 0; i < fmax(a.length(), b.length()); i++) {
            int temp = 0;
            if (i < a.length()) temp += a[i] - '0';
            if (i < b.length()) temp += b[i] - '0';
            if (prevSum >= 10) temp++;
            
            result += (temp % 10) + '0';
            prevSum = temp;
        }
        if (prevSum >= 10) result += "1";
        for (int i = 0; i < result.length(); i++) {
            if (result[i] != '0') {
                cout << result.substr(i) << "\n";
                break;
            }
        }
    }

    return 0;
}