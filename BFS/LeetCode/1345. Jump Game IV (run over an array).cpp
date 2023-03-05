class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[arr[i]].push_back(i);
        }
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int step = 0;
        while (!q.empty()) {
            int siz = q.size();
            while (siz--) {
                int u = q.front();
                if (u == (n - 1)) return step;
                q.pop();
                if (u != 0 and !vis[u - 1]) {
                    vis[u - 1] = 1;
                    q.push(u - 1);
                }
                if (!vis[u + 1]) {
                    vis[u + 1] = 1;
                    q.push(u + 1);
                }
                for (auto v : adj[arr[u]]) {
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
                adj[arr[u]].clear();
            }
            step++;
        }
        return -1;
    }
};


