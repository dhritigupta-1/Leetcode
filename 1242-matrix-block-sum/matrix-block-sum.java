class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int n = mat.length;
        int m = mat[0].length;
        int [][] prefix = new int [n+1][m+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                prefix[i][j] = mat[i-1][j-1] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            }       
        }
        int ans[][] = new int [n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int r = Math.max(0, i-k);
                int c = Math.max(0, j-k);
                int r1 = Math.min(n-1, i+k);
                int c1 = Math.min(m-1, j+k);
                ans[i][j] = prefix[r1+1][c1+1] - prefix[r][c1+1] - prefix[r1+1][c] + prefix[r][c];
            }
        }
        return ans;
    }
}