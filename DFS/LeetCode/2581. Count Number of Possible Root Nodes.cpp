class Solution {
public:
    int res, vis[200000];
    map<pair<int, int>, int> mark;
    vector<int> adj[200000];
    int get_cnt(int root) {
        vis[root] = 1;
        int cnt = 0;
        for (auto i : adj[root]) {
            if (!vis[i]) {
                cnt += mark[{root, i}] + get_cnt(i);
            }
        }
        return cnt;
    }

    void dfs(int root, int k, int cnt) {
        if (cnt >= k) res++;
        vis[root] = 1;
        for (auto i : adj[root]) {
            if (!vis[i]) {
                dfs(i, k, cnt - mark[{root, i}] + mark[{i, root}]);
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (auto i : guesses) {
            mark[{i[0], i[1]}] = 1;
        }
        int cnt = get_cnt(0);
        for (int i = 0; i <= n; i++) vis[i] = 0;
        dfs(0, k, cnt);
        return res;
    }
};

