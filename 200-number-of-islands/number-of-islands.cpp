class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] == '0' || vis[i][j]) return;
        //grid[i][j] = '0'; // mark as visited
        vis[i][j] = true;
        // chheck all 4 directions
        DFS(grid, vis, i-1, j, n, m);
        DFS(grid, vis, i, j-1, n, m);
        DFS(grid, vis, i, j+1, n, m);
        DFS(grid, vis, i+1, j, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    DFS(grid, vis, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};