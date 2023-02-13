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



//c#

public class Solution {
    long res;
    private int dfs(Dictionary<int, List<int>> adj, int root, int par, int seats) {
        int cnt = 1;
        foreach (var i in adj[root]) {
            if (i != par) cnt += dfs(adj, i, root, seats);
        }
        if (root != 0) {
            res += cnt / seats;
            if (cnt % seats != 0) res++;
        }
        return cnt;
    }

    public long MinimumFuelCost(int[][] roads, int seats) {
        if(roads.GetLength(0) == 0) return 0;
        res = 0;
        var adj = new Dictionary<int, List<int>> ();
        foreach (var i in roads) {
            if (!adj.ContainsKey(i[0])) {
                adj[i[0]] = new List<int> ();
            }
            if (!adj.ContainsKey(i[1])) {
                adj[i[1]] = new List<int> ();
            }
            adj[i[0]].Add(i[1]);
            adj[i[1]].Add(i[0]);
        }
        dfs(adj, 0, 0, seats);
        return res;
    }
}



