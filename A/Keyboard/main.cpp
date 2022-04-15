#include <bits/stdc++.h>
using namespace std;

int main() {

    string key[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    char shift; cin >> shift;
    string input; cin >> input;
    string result;

    for (int i = 0; i < input.length(); i++) {
        for (int row = 0; row < 3; row++) {
            if (key[row].find(input[i]) != string::npos) {
                int pos = key[row].find(input[i]);

                if (shift == 'R') pos -= 1;
                else pos += 1;

                result += key[row][pos];
                break;
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}