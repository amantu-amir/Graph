//https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int res;
    vector<int> adj[100010];
    void dfs(int root, int curr, vector<int>& informTime) {
        if (adj[root].size() == 0) {
           res = max(res, curr);
           return;
        }
        for (auto i : adj[root]) {
            dfs(i, curr + informTime[root], informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) adj[manager[i]].push_back(i);
        }
        dfs(headID, 0, informTime);
        return res;
    }
};


