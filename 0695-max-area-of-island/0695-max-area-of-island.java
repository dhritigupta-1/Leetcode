class Solution {
    int temp = 0;
    int DFS(int[][] grid, int i, int j, int r, int c)
    {
        if(i==r || j==c || i<0 || j<0 || grid[i][j] == 0)
            return 0;
        temp++;
        grid[i][j] = 0;
        DFS(grid, i, j+1, r, c);
        DFS(grid, i-1, j, r, c);
        DFS(grid, i, j-1, r, c);
        DFS(grid, i+1, j, r, c);
        return temp;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int ans = 0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    temp = 0;
                    DFS(grid, i, j, r, c);
                    ans = Math.max(ans, temp);
                }
            }
        }
        return ans;
    }
}