//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/adjacent-sum-greater-than-k-f41e3ec4/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rep[300010];

ll find(ll r) {
    if (rep[r] == r) return r;
    else return rep[r] = find(rep[r]);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if ((1 + n) < k) {
            cout << "-1\n";
            continue;
        }
        for (ll i = 0; i <= n; i++) rep[i] = i;
        vector<ll> res;
        res.push_back(1);
        rep[0] = 1;
        rep[1] = 2;
        ll curr = find(k - 1);
        res.push_back(curr);
        rep[curr] = find(curr + 1);
        while (n > 2) {
            if (curr >= k) {
                curr = find(1);
                res.push_back(curr);
                rep[curr] = find(curr + 1);
            }
            else {
                curr = find(k - curr);
                res.push_back(curr);
                rep[curr] = find(curr + 1);
            }
            n--;
        }
        for (auto i : res) cout << i << " ";
        cout << "\n";
    }
    return 0;
}


