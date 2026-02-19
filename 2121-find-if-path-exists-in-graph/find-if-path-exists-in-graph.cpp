class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int source, int destination){
        if(source == destination) return true;
        vis[source] = true;
        for(auto nbr : adj[source]){
            if(!vis[nbr]){
                if(dfs(adj, vis, nbr, destination)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return dfs(adj, vis, source, destination);
    }
};