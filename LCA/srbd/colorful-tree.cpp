#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 5e5 + 50, mod = 1e9 + 7;

class data {
public:
	ll depth, sum;
};

string s;
ll somoy = 1, sparse[N][22], sum[N];
vector<ll> adj[N], tin(N), tout(N);

void dfs(ll root, ll par) {
	tin[root] = somoy++;
	sparse[root][0] = par;
	for (ll i = 1; i <= 20; i++) {
		sparse[root][i] = sparse[sparse[root][i - 1]][i - 1];
	}
	for (auto i : adj[root]) {
		if (i != par) {
			sum[i] = sum[root] + (s[i - 1] - '0');
			dfs(i, root);
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
	//https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll node, q;
    cin >> node >> q;
    sum[1] = somoy = 1;
    for (ll i = 0; i <= node; i++) {
    	adj[i].clear();
    }
    for (ll i = 1; i <= (node - 1); i++) {
    	ll u;
    	cin >> u;
    	adj[u].push_back(i + 1);
    	adj[i + 1].push_back(u);
    }
    cin >> s;
    dfs(1, 1);
    while (q--) {
    	ll u, v;
    	cin >> u >> v;
    	ll lca = getLca(u, v);
    	ll totalSum = sum[u] + sum[v] - (2 * sum[lca]) + 1;
    	cout << totalSum << "\n";
    }
  }
  return 0;
}



