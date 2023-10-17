#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

vector<ll> adj[N];
vector<pair<ll, ll>> A[N];
unordered_map<ll, ll> mark;
ll timer, sparse[N][22], tin[N], tout[N], w[N];

void dfs(ll root, ll par, bool flag) {
	if (flag == 0) {
		tin[root] = ++timer;
		sparse[root][0] = par;
		for (ll i = 1; i <= 20; ++i) {
			sparse[root][i] = sparse[sparse[root][i - 1]][i - 1];
		}
	}
	if(flag) {
		mark[w[root]]++;
		ll siz = A[root].size();
		for (ll i = 0; i < siz; i++) {
			A[root][i] = {A[root][i].first, mark[A[root][i].first]};
		}
	}
	for (auto i : adj[root]) if (i != par) dfs(i, root, flag);
	if (flag) mark[w[root]]--;
	if (flag == 0) tout[root] = ++timer;
}

bool isAncestor(ll u, ll v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

ll getLca(ll u, ll v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
	for (ll i = 20; i >= 0; --i) {
		if (isAncestor(sparse[u][i], v) == 0) u = sparse[u][i];
	}
	return sparse[u][0];
}

ll getK(ll i, ll k) {
	ll l = 0, r = A[i].size() - 1, res;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (A[i][mid].first == k) {res = A[i][mid].second; break;}
		if (A[i][mid].first < k) l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll node;
    cin >> node;
    for (ll i = 0; i < node; i++) cin >> w[i];
    for (ll i = 0; i < (node - 1); i++) {
    	ll u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(0, 0, 0);
    ll q;
    cin >> q;
    vector<vector<ll>> Q;
    while (q--) {
    	ll u, v, k;
    	cin >> u >> v >> k;
    	ll lca = getLca(u, v);
    	Q.push_back({u, v, lca, k});
    	A[u].push_back({k, 0});
    	A[v].push_back({k, 0});
    	if (lca != u and lca != v) A[lca].push_back({k, 0});
    }
    for (ll i = 0; i < node; i++) {
    	sort(A[i].begin(), A[i].end());
    }
    dfs(0, 0, 1);
    q = Q.size();
    for (ll i = 0; i < q; ++i) {
      ll u = Q[i][0], v = Q[i][1], lca = Q[i][2], k = Q[i][3];
      ll uk = getK(u, k), vk = getK(v, k), lcak = getK(lca, k);
      ll res = uk + vk - (2 * lcak);
    	if (w[lca] == k) res++;
    	cout << res << "\n";
    }
  }
  return 0;
}



