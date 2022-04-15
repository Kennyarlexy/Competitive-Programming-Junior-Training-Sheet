#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int crime = 0, officer = 0;
    while (n--) {
        int input; cin >> input;
        if (input == -1) {
            if (officer == 0) {
                crime++;
            } else {
                officer--;
            }
        } else {
            officer += input;
        }
    }
    
    cout << crime << endl;
    
    return 0;
}