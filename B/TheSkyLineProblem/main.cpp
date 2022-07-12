#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Wall {
    ll x;
    ll h;
    ll type;
    Wall(ll xt, ll ht, ll typet) {
        x = xt;
        h = ht;
        type = typet;
    }
};

vector<Wall> W;
bool cmp1(Wall A, Wall B) {
    return (A.x < B.x);
}

//it's possible to not using cmp2, just use rbegin() to get the largest element on regular set or multiset
struct cmp2 {
    bool operator () (ll h1, ll h2) {
        return (h1 > h2);
    }
};

int main() {
    fast_io();
    //use ll when possible!
    ll L, H, R;
    while (cin >> L >> H >> R) {
        W.emplace_back(L, H, 1);
        W.emplace_back(R, H, 2);
    }

    sort(W.begin(), W.end(), cmp1);

    //i think that below's implementation is also possible with regular set, but we need to store the cnt of each height so that we only erase it when the cnt is 0. multiset just does this for us since it stores multiple item with the same value and it takes the same amount of erase as the amount of insert to completely erase it.
    multiset<ll, cmp2> ch; //store current building heights
    ch.insert(0);
    vector<pair<ll, ll>> res;
    ll erasedHighest = 0, insertedHighest = 0;
    for (ll i = 0; i < W.size(); i++) {
        if (W[i].type == 1) {
            if (W[i].h > *ch.begin()) insertedHighest = max(insertedHighest, W[i].h);
            ch.insert(W[i].h); //this height is available
        } else {
            ch.erase(ch.find(W[i].h)); //this height is not available
            if (W[i].h > *ch.begin()) erasedHighest = max(erasedHighest, W[i].h);
        }

        if (i != W.size() - 1 && W[i].x != W[i+1].x && insertedHighest != erasedHighest) {
            res.emplace_back(W[i].x, *ch.begin());
            insertedHighest = 0;
            erasedHighest = 0;
        }
    }

    for (auto& data : res) {
        std::cout << data.first << " " << data.second << " ";
    }
    cout << W.back().x << " 0\n";

    return 0;
}