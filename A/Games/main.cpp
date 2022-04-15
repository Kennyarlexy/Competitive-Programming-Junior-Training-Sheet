#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int team[n][2];
    for (int i = 0; i < n; i++) {
        cin >> team[i][0] >> team[i][1];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (team[i][0] == team[j][1]) {
                count++;
            }
            if (team[i][1] == team[j][0]) {
                count++;
            }
        }
    }
    cout << count << endl;
    
    return 0;
}