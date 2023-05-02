class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }
    int find(int r, vector<int>& rep) {
        if (r == rep[r]) return r;
        return rep[r] = find(rep[r], rep);
    }
    bool isConnected(int u, int v, vector<int>& rep) {
        return find(u, rep) == find(v, rep);
    }
    void join_node(int u, int v, vector<int>& rep, vector<int>& rank) {
        u = find(u, rep), v = find(v, rep);
        if (u != v) {
            if (rank[u] > rank[v]) {
                rep[v] = u, rank[u] += rank[v];
            }
            else {
                rep[u] = v, rank[v] += rank[u];
            }
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int siz = edges.size();
        sort(edges.begin(), edges.end(), cmp);
        vector<int> rep_alice(n + 5), rep_bob(n + 5), rank_alice(n + 5), rank_bob(n + 5);
        for (int i = 0; i <= n; i++) {
            rep_alice[i] = rep_bob[i] = i;
            rank_alice[i] = rank_bob[i] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < siz; i++) {
            if (edges[i][0] == 3) {
                bool ok = 0;
                if (!isConnected(edges[i][1], edges[i][2], rep_alice)) {
                    ok = 1;
                    join_node(edges[i][1], edges[i][2], rep_alice, rank_alice);
                }
                if (!isConnected(edges[i][1], edges[i][2], rep_bob)) {
                    ok = 1;
                    join_node(edges[i][1], edges[i][2], rep_bob, rank_bob);
                }
                if (ok) cnt++;
            }
            else if (edges[i][0] == 1) {
                if (!isConnected(edges[i][1], edges[i][2], rep_alice)) {
                    cnt++;
                    join_node(edges[i][1], edges[i][2], rep_alice, rank_alice);
                }
            }
            else {
                if (!isConnected(edges[i][1], edges[i][2], rep_bob)) {
                    cnt++;
                    join_node(edges[i][1], edges[i][2], rep_bob, rank_bob);
                }
            }
        }
        if (rank_alice[find(edges[0][1], rep_alice)] != n) return -1;
        if (rank_bob[find(edges[0][1], rep_bob)] != n) return -1;
        return siz - cnt;
    }
};


