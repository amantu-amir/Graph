#include<iostream>
using namespace std;
typedef long long ll;

ll adj[30][30], vis[30][30];

ll dfs(ll root) {
    ll res = 0;
    for (ll i = 0; i <= 25; i++) {
        if (!vis[root][i] and adj[root][i]) {
            vis[root][i] = vis[i][root] = 1;
            res = max(res, 1 + dfs(i));
            vis[root][i] = vis[i][root] = 0;
        }
    }
    return res;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll node, edge;
    while (cin >> node >> edge) {
        if ((node + edge) == 0) break;
        ll u, v;
        for (ll i = 1; i <= edge; i++) {
            cin >> u >> v;
            adj[u][v] = 1; 
            adj[v][u] = 1;
        }
        ll res = 0;
        for (ll i = 0; i <= (node - 1); i++) {
            res = max(res, dfs(i));
        }
        cout << res << "\n";
        for (ll i = 0; i <= 25; i++) {
            for (ll j = 0; j <= 25; j++) {
                adj[i][j] = vis[i][j] = 0;
            }
        }
    }
    return 0;
}



