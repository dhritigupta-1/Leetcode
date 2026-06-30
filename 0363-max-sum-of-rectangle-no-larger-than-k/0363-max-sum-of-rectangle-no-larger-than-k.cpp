class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int i1=i; i1<n; i1++){
                    for(int j1=j; j1<m; j1++){
                        int sum = prefix[i1+1][j1+1] - prefix[i][j1+1] - prefix[i1+1][j] + prefix[i][j];
                        if(sum <= k)
                            ans = max(ans, sum);
                    }
                }
            }
        }
        return ans;
    }
};