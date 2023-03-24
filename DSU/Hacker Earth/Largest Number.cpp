//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rep[1000100];

ll find(ll r) {
    if (r == rep[r]) return r;
    else return rep[r] = find(rep[r]);
}

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size(), currK = k;
    for (ll i = 0; i <= n; i++) rep[i] = i;
    for (ll i = 1; i < n and currK; i++) {
        ll idx = find(i - 1);
        while (currK && idx >= 0 && s[idx] != 'a' && s[idx] < s[i]) {
            s[idx] = 'a';
            currK--;
            if ((idx - 1) >= 0) {
                rep[idx] = find(idx - 1);
                idx = find(idx - 1);
            }
        }
    }
    ll tot = n - k;
    for (ll i = 0; i < n; i++) {
        if (s[i] != 'a' and tot) {
            cout << s[i];
            tot--;
        }
    }
    cout << "\n";
    return 0;
}
