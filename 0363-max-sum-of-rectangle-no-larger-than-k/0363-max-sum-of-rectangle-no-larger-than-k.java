class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] prefix = new int [n+1][m+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                prefix[i][j] = matrix[i-1][j-1] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int i1=i; i1<n; i1++){
                    for(int j1=j; j1<m; j1++){
                        int sum = prefix[i1+1][j1+1] - prefix[i][j1+1] - prefix[i1+1][j] + prefix[i][j];
                        if(sum <= k) ans = Math.max(sum, ans);
                    }
                }
            }
        }
        return ans;
    }
}