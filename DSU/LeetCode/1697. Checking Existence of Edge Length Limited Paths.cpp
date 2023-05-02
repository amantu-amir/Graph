
class Solution {
public:
    int rep[100010], rank[100010];
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    int find(int r) {
        if (r == rep[r]) return r;
        return rep[r] = find(rep[r]);
    }
    void join_node(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] > rank[v]) {
                rep[v] = u;
                rank[u] += rank[v];
            }
            else {
                rep[u] = v;
                rank[v] += rank[u];
            }
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int siz = queries.size(), edges = edgeList.size();
        for (int i = 0; i < siz; i++) {
            queries[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);
        for (int i = 0; i <= n; i++) {
            rep[i] = i, rank[i] = 1;
        }
        int idx = 0;
        vector<bool> res(siz, false);
        for (int i = 0; i < siz; i++) {
            int u = queries[i][0], v = queries[i][1], weightLimit = queries[i][2], id = queries[i][3];
            while (idx < edges and edgeList[idx][2] < weightLimit) {
                int a = edgeList[idx][0], b = edgeList[idx][1];
                join_node(a, b);
                idx++;
            }
            if (find(u) == find(v)) res[id] = true;
        }
        return res;
    }
};



