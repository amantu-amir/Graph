class Solution {
public:
    long long res;
    vector<int> adj[100010];
    int dfs(int root, int par, int seats) {
        int cnt = 1;
        for (auto i : adj[root]) {
            if (i != par) {
                cnt += dfs(i, root, seats);
            }
        }
        if (root != 0) res += (cnt / seats) + (cnt % seats != 0);
        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        for (int i = 0; i < n; i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int temp = dfs(0, -1, seats);
        return res;
    }
};


