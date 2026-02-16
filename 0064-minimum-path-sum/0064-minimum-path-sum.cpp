class Solution {
public:
    int Func(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int top = Func(grid, i-1, j, dp);
        int left = Func(grid, i, j-1, dp);
        return dp[i][j] = grid[i][j] + min(top, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // for(int j=1; j<m; j++)
        //     grid[0][j] = grid[0][j] + grid[0][j-1];
        // for(int i=1; i<n; i++)
        //     grid[i][0] = grid[i][0] + grid[i-1][0];
        // for(int i=1; i<n; i++)
        // {
        //     for(int j=1; j<m; j++)
        //     {
        //         grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
        //     }
        // }
        // return grid[n-1][m-1];
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Func(grid, n-1, m-1, dp);
    }
};