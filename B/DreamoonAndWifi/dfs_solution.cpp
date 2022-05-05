#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char adj[] = {'+', '-'};
int len;
int diff;
int possible = 0;
int unknown = 0;

void dfs(char current = ' ', int count = 0, int depth = 0) {
    if (current == '+') count++;
    if (depth == unknown) {
        if (count == diff) possible++;
        return;
    }

    for (auto& next : adj) {
        dfs(next, count, depth + 1);
    }
}

int main() {
    fast_io();
    string s1, s2; cin >> s1 >> s2;
    len = s1.length();
    int pos_1 = 0, pos_2 = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] == '+') pos_1++;
        if (s2[i] == '+') pos_2++;
        else if (s2[i] == '?') unknown++;
    }
    diff = pos_1 - pos_2;
    dfs();

    int total = pow(2, unknown);
    double result = (double) possible / total;
    cout << fixed << setprecision(10) << result << "\n";

    return 0;
}