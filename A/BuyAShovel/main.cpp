#include <iostream>
using namespace std;

int main() {
    int price, coin; cin >> price >> coin;
    int n = 1;
    while ((price * n) % 10 != 0 && (price * n) % 10 != coin) {
        n++;
    }
    cout << n << endl;
    
    return 0;
}