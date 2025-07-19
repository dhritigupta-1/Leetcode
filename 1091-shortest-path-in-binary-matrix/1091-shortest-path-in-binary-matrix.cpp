class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(grid[0][0]==1 || grid[r-1][c-1]==1) return -1;
        int count=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        vector<int> dx = {0,0,1,-1,1,1,-1,-1};
        vector<int> dy = {1,-1,0,0,1,-1,1,-1};
        while(q.size()>0)
        {
            int size=q.size();
            for(int i=0; i<size; i++)
            {
                pair<int,int> node = q.front();
                q.pop();
                if(node.first==r-1 && node.second==c-1)
                    return count;
                for(int j=0; j<8; j++)
                {
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y] = 1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};