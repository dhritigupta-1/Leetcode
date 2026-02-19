class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited){
        visited[i] = 1;
        for(int x : adj[i]){
            if(!visited[x]){
                dfs(x, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // convert adjancy matrix to adjancy list
        vector<vector<int>> adj(isConnected.size());
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                provinces++;
                dfs(i, adj, visited);
            }
        }
        return provinces;
    }
};