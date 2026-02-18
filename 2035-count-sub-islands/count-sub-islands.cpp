class Solution {
public:
    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j] == 0) return true;
        grid2[i][j] = 0;
        bool valid = (grid1[i][j] == 1);
        valid &= DFS(grid1, grid2, i+1, j, n, m);
        valid &= DFS(grid1, grid2, i, j+1, n, m);
        valid &= DFS(grid1, grid2, i, j-1, n, m);
        valid &= DFS(grid1, grid2, i-1, j, n, m);
        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1){
                    if(DFS(grid1, grid2, i, j, n, m))
                        ans++;
                }
            }
        }
        return ans;
    }
};