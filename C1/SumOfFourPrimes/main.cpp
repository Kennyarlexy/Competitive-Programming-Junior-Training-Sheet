#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool used[10000005];
bool isPrime[10000005];
ll prime[10000005]; //664579

int main() {
    fast_io();
    //use ll when possible!
    ll k = 0;
    for (ll i = 2; i <= 10000000; i++) {
        if (used[i]) continue;
        isPrime[i] = true;
        prime[k++] = i;
        for (ll j = i; j <= 10000000; j+=i) {
            used[j] = true;
        }
    }

    ll N;
    while (cin >> N) {
        ll OK = false;
        ll x, y;
        ll temp = (N % 2 == 0 ? N - 4 : N - 5);
        for (ll i = 0; i < 664579; i++) {
            if (prime[i] > temp / 2) break;
            
            if (isPrime[temp - prime[i]]) {
                x = prime[i];
                y = temp - x;
                OK = true;
                break;
            }
        }

        if (OK) {
            if (N % 2 == 0) {
                cout << "2 2 " << x << " " << y << "\n";
            } else {
                cout << "2 3 " << x << " " << y << "\n";
            }
        } else {
            cout << "Impossible.\n";
        }
    }

    return 0;
}