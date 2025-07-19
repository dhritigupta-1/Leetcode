class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        vector<int> dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};        
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
                    if(x>=0 && y>=0 && x<r && y<c && maze[x][y]=='.')
                    {
                        if(x==0 || y==0 || x==r-1 || y==c-1)
                            return count+1;
                        q.push({x,y});
                        maze[x][y] = '+';
                    }
                }
            }
            count++;
        }
        return -1;
    }
};