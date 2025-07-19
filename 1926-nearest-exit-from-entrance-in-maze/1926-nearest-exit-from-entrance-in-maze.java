class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int r = maze.length;
        int c = maze[0].length;
        int[] dx = {0,0,1,-1};
        int[] dy = {1,-1,0,0};
        int count = 0;
        Queue<Pair<Integer,Integer>> q = new LinkedList<>();
        q.add(new Pair<>(entrance[0],entrance[1]));
        maze[entrance[0]][entrance[1]] = '+';
        while(q.size() > 0)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Pair<Integer,Integer> node = q.poll();
                for(int j=0; j<4; j++)
                {
                    int x = node.getKey() + dx[j];
                    int y = node.getValue() + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && maze[x][y]=='.')
                    {
                        if(x==0 || y==0 || x==r-1 || y==c-1) 
                            return count+1;
                        q.add(new Pair<>(x,y));
                        maze[x][y]='+';
                    }
                }
            }
            count++;
        }
        return -1;
    }
}