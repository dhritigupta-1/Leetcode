class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j, int n, int m){
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0'; // mark visited
        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
        while(!q.empty()){
            auto[x, y] = q.front(); q.pop();
            for(auto [dx, dy] : directions){
                int newX = x + dx, newY = y + dy;
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1'){
                    q.push({newX, newY});
                    grid[newX][newY] = '0'; // mark visited
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' ){ 
                    BFS(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};