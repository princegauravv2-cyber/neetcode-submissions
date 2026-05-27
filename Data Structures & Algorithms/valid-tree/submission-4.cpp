class Solution {
public:
    bool dfs(const vector<vector<int>>& adj, int v, int p, unordered_set<int>& vis) {
        if(vis.find(v) != vis.end()) {
            return false;
        }
        vis.insert(v);
        for(const auto& i : adj[v]) {
            if(i != p) {
                bool ret = dfs(adj, i, v, vis);
                if(!ret)
                    return ret;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(const auto& i : edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        unordered_set<int> vis;
        bool ret = dfs(adj, 0, -1, vis);
        if(!ret)
            return false;
        while(n--) {
            if(vis.find(n) == vis.end())
                return false;
        }
        return true;
    }
};
