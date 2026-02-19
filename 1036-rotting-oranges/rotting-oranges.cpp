class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis = grid;
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        queue<pair<int, int>> q;
        int min = 0, fresh = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(vis[i][j] == 1) fresh++;
                else if(vis[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int, int> node = q.front(); q.pop();
                for(int j=0; j<4; j++){
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && vis[x][y]==1){
                        vis[x][y] = 2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
            if(q.size()) min++;
        }
        if(fresh == 0) return min;
        return -1;
    }
};