#include<iostream>
using namespace std;

typedef long long ll;


bool vis[15], found;
ll adj[15][15], path[15], n, path_len;

void dfs(ll root, ll currLen) {
    if (currLen == path_len) {
        found = 1;
        cout << "(1";
        for (ll i = 0; i < path_len; i++) {
            cout << "," << path[i];
        }
        cout << ")\n";
        return;
    }
    for (ll i = 1; i <= n; i++) {
        if (adj[root][i] and !vis[i]) {
            vis[i] = 1;
            path[currLen] = i;
            dfs(i, currLen + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    bool flag = 0;
    while (cin >> n >> path_len) {
        if (flag) cout << "\n";
        flag = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }
        found = 0, vis[1] = 1;
        for (ll i = 2; i < 15; i++) vis[i] = 0;
        dfs(1, 0);
        if (!found) cout << "no walk of length " << path_len << "\n";
        ll garbage;
        cin >> garbage;
    }
}
