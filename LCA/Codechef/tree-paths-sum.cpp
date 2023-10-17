#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

class Node {
public:
	ll child, weight;
};

vector<Node> adj[N];
ll tin[N], tout[N], cost[N], sparse[N][22], somoy;

void dfs(ll root, ll par) {
	tin[root] = somoy++;
	sparse[root][0] = par;
	for (ll i = 1; i <= 20; i++) {
		sparse[root][i] = sparse[sparse[root][i - 1]][i - 1];
	}
	for (auto i : adj[root]) {
		if (i.child != par) {
			cost[i.child] = cost[root] + i.weight;
			dfs(i.child, root);
		}
	}
	tout[root] = somoy++;
}

bool isAncestor(ll u, ll v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

ll getLca(ll u, ll v) {
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
    ll node, q, root;
    cin >> node >> q >> root;
    somoy = 1, cost[root] = 0;
    for (ll i = 0; i <= node; i++) {
    	adj[i].clear();
    }
    for (ll i = 0; i < (node - 1); i++) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    dfs(root, root);
    while (q--) {
    	ll u, v;
    	cin >> u >> v;
    	ll lca = getLca(u, v);
    	ll res = cost[u] + cost[v] - (2 * cost[lca]);
    	cout << res << "\n";
    }
  }
  return 0;
}



