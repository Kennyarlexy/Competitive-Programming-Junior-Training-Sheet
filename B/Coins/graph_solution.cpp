#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[3];
bool visited[3];
bool dfsVisited[3];
vector<char> result;


//this function can also be named hasCycle()
bool dfs(int current) {
    if (visited[current]) {
        return (dfsVisited[current] ? true : false);
    }

    visited[current] = true;
    dfsVisited[current] = true;

    bool hasCycle = false;
    for (auto& next : adj[current]) {
        hasCycle = dfs(next);
    }

    dfsVisited[current] = false;
    result.push_back(current + 'A');

    return hasCycle;
}


int main() {
    for (int i = 0; i < 3; i++) {
        string input; cin >> input;
        if (input[1] == '>') {
            adj[input[0] - 'A'].push_back(input[2] - 'A');
        } else {
            adj[input[2] - 'A'].push_back(input[0] - 'A');
        }
    }

    for (int coin = 0; coin < 3; coin++) {
        if (!visited[coin]) {
            if (dfs(coin)) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    for (auto& data : result) {
        cout << data;
    }
    cout << "\n";

    return 0;
}