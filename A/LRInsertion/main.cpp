//TLE, need to find better solution using dequeue

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v = {0};
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'L') {
            v.insert(v.begin() + pos, i);
        } else {
            v.insert(v.begin() + pos + 1, i);
            pos++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    
    return 0;
}