#include <iostream>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int width = 0;
    while (n--) {
        int personHeight; cin >> personHeight;
        if (personHeight > h) {
            width += 2;
        } else {
            width += 1;
        }
    }
    cout << width << endl;
    
    return 0;
}