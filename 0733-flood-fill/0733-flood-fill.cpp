class Solution {
public:
    void DFS(vector<vector<int>>& image, int i, int j, int r, int c, int old, int color)
    {
        if(i==r || j==c || i<0 || j<0 || image[i][j] != old || image[i][j] == color)
            return;
        image[i][j] = color;
        DFS(image, i, j+1, r, c, old, color);
        DFS(image, i-1, j, r, c, old, color);
        DFS(image, i, j-1, r, c, old, color);
        DFS(image, i+1, j, r, c, old, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        int old = image[sr][sc];
        DFS(image, sr, sc, r, c, old, color);
        return image;
    }
};