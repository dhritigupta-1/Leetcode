class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        DFS(grid, i-1, j, n, m);
        DFS(grid, i, j-1, n, m);
        DFS(grid, i, j+1, n, m);
        DFS(grid, i+1, j, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};