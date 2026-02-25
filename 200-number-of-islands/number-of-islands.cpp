class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j, int n, int m){
        queue<pair<int, int>> q;
        q.push({i,j});
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto [dx, dy] : directions){
                int newX = node.first + dx;
                int newY = node.second + dy;
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]=='1'){
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
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
                if(grid[i][j]=='1'){
                    BFS(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};