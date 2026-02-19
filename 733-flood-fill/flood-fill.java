class Solution {
    void DFS(int[][] image, int i, int j, int r, int c, int old, int color)
    {
        if(i==r || j==c || i<0 || j<0 || image[i][j] != old || image[i][j] == color)
            return;
        image[i][j] = color;
        DFS(image, i, j+1, r, c, old, color);
        DFS(image, i-1, j, r, c, old, color);
        DFS(image, i, j-1, r, c, old, color);
        DFS(image, i+1, j, r, c, old, color);
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int r = image.length;
        int c = image[0].length;
        int old = image[sr][sc];
        DFS(image, sr, sc, r, c, old, color);
        return image;
    }
}