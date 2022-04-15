#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int card[n];
    int Sereja = 0, Dima = 0;
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        int add = 0;
        if (card[left] > card[right]) {
            add = card[left];
            left++;
        } else {
            add = card[right];
            right--;
        }

        if (i % 2 == 0) {
            Sereja += add;
        } else {
            Dima += add;
        }
    }
    cout << Sereja << " " << Dima << endl;
    
    return 0;
}