#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define Mid(b, e) b + (e - b) / 2
#define inf 1e18
double PI = 2 * acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};

void yesNo(bool ck){cout << (ck ? "YES\n" : "NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

vector<ll> adj[N];
vector<pair<ll, ll>> cost(N);

void dfs(ll root, ll par, ll val) {
    for (auto i : adj[root]) {
        if (i != par) {
            dfs(i, root, val);
        }
    }
    ll cnt = 0, w = 0;
    for (auto i : adj[root]) {
        if (i != par) {
            if (cost[i].F <= val) {
                if (cost[i].S > cnt) {
                    cnt = cost[i].S;
                    w = cost[i].F;
                }
            }
        }
    }
    cost[root].F = max(cost[root].F, w);
    cost[root].S += cnt;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll node, k;
        cin >> node >> k;
        vector<ll> w(node);
        for (ll i = 1; i <= node; i++) {
            cin >> w[i - 1];
        }
        ll u, v;
        for (ll i = 1; i <= (node - 1); i++) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll root;
        for (ll i = 1; i <= node; i++) {
            if (adj[i].size() == 1) {
                root = i; break;
            }
        }
        vector<ll> weight = w;
        sort(all(w));
        ll L = 0, R = node - 1, res = -1;
        while (L <= R) {
            ll mid = L + (R - L) / 2;
            for (ll i = 1; i <= node; i++) {
                cost[i].F = weight[i - 1];
                cost[i].S = 1;
            }
            dfs(root, -1, w[mid]);
            bool ok = 0;
            for (ll i = 1; i <= node; i++) {
                if (cost[i].S > k) {
                    ok = 1; break;
                }
            }
            if (ok) {
                res = w[mid];
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}





