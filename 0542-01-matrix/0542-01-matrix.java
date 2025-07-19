class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;
        Queue<Pair<Integer,Integer>> q = new LinkedList<>();
        int[] dx = {0,0,1,-1};
        int[] dy = {1,-1,0,0};
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.add(new Pair<>(i,j));
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
                Pair<Integer,Integer> node = q.poll();
                for(int j=0; j<4; j++)
                {
                    int x = node.getKey() + dx[j];
                    int y = node.getValue() + dy[j];
                    if(x>=0 && y>=0 && x<r && y<c && mat[x][y]==-1 )
                    {
                        q.add(new Pair<>(x,y));
                        mat[x][y] = mat[node.getKey()][node.getValue()] + 1;
                    }
                }
            }
        }
        return mat;
    }
}