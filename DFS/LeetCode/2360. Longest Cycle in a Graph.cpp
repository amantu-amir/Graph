class Solution {
public:
    static const int N = 100100;
    bool vis[N];
    int res;
    vector<int> adj[N], path;
    void dfs(int root) {
        vis[root] = 1;
        path.push_back(root);
        for (auto i : adj[root]) {
            if (vis[i]) {   //back edge (back edge make cycle)
                int siz = path.size(), cnt = 0;
                for (int j = 0; j < siz; j++) {
                    if (path[j] == i) break;
                    cnt++;
                }
                res = max(res, siz - cnt);
            }
            else {
                dfs(i);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            if (edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            path.clear();
            dfs(i);
        }
        if (res <= 1) res = -1;
        return res;
    }
};


