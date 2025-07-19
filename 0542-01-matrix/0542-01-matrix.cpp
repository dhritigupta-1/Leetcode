class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        queue<pair<int,int>> q;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
                else if(mat[i][j] == 1)
                {
                    mat[i][j] = -1;
                }
            }
        }
        while(q.size() > 0)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int,int> node = q.front();
                q.pop();
                for(int j=0; j<4; j++)
                {
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && mat[x][y]==-1 )
                    {
                        q.push({x,y});
                        mat[x][y] = mat[node.first][node.second] + 1;
                    }
                }
            }
        }
        return mat;
    }
};