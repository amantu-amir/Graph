#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

string s;
vector<ll> adj[N];
ll n, sparse[N][22], tree[N][30], tin[N], tout[N], somoy;

void dfs(ll root, ll par) {
	tin[root] = somoy++;
	sparse[root][0] = par;
	for (ll i = 1; i <= 20; i++) {
		sparse[root][i] = sparse[sparse[root][i - 1]][i - 1];
	}
	tree[root][s[root - 1] - 'a' + 1]++;
	for (auto i : adj[root]) {
		if (i == par) continue;
		for (ll j = 1; j <= 26; j++) {
			tree[i][j] = tree[root][j];
		}
		dfs(i, root);
	}
	tout[root] = somoy++;
}

bool isAncestor(ll u, ll v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

ll query(ll u, ll v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
	for (ll i = 20; i >= 0; i--) {
		if (!isAncestor(sparse[u][i], v)) u = sparse[u][i];
	}
	return sparse[u][0];
}

int main() {
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    cin >> n >> s;
    somoy = 1;
    for (ll i = 1; i <= n; i++) {
    	adj[i].clear();
    	for (ll j = 0; j <= 26; j++) tree[i][j] = 0;
    }
    for (ll i = 0; i < (n - 1); i++) {
    	ll u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1, 1);
    ll q;
    cin >> q;
    while (q--) {
    	ll u, v;
    	cin >> u >> v;
    	ll lca = query(u, v), ok = 0;
    	for (ll i = 1; i <= 26; i++) {
    		ll a = tree[u][i] - tree[lca][i], b = tree[v][i] - tree[lca][i];
    		if (a and b) { ok = 1; break; }
    	}
    	cout << (ok ? "YES\n" : "NO\n");
    }
  }
  return 0;
}



