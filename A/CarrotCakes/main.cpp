#include <bits/stdc++.h>
using namespace std;

int main() {
    int target, bakingTime, cakePerOven, buildingTime;
    cin >> target >> bakingTime >> cakePerOven >> buildingTime;

    int time = 0;
    int bakedCake = 0;
    while (bakedCake < target) {
        time++;
        if (time % bakingTime != 0 && (time - buildingTime) % bakingTime != 0) {
            continue;
        }
        if (time % bakingTime == 0) {
            bakedCake += cakePerOven;
        }

        if ((time - buildingTime) % bakingTime == 0 && time > buildingTime) {
            bakedCake += cakePerOven;
        }
    }

    int rounds = target / cakePerOven;
    if (cakePerOven*rounds < target) {
        rounds += 1;
    }
    
    int normalTime = rounds * bakingTime;
    if (time < normalTime) {
        cout << "YES\n";
    }  else {
        cout << "NO\n";
    }
    
    return 0;
}