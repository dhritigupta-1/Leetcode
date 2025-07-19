class Solution {
    public int orangesRotting(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int fresh=0, rotten=0, min=0, ans;
        int[] dx = {0,0,1,-1};
        int[] dy = {1,-1,0,0};
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                {
                    rotten++;
                    q.add(new Pair<>(i, j));
                }
            }
        }
        while(q.size() > 0)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Pair<Integer, Integer> node = q.poll();
                for(int j=0; j<4; j++)
                {
                    int x = node.getKey() + dx[j];
                    int y = node.getValue() + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y] == 1)
                    {
                        q.add(new Pair<>(x, y));
                        grid[x][y] = 2;
                        fresh--;
                    }
                }
            }
            if(!q.isEmpty()) min++;
        }
        if(fresh == 0) return min;
        return -1;
    }
}