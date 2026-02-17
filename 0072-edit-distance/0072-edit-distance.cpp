class Solution {
public:
    int func(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i==0 ) return j; // if(i < 0) return j+1;
        if(j == 0) return i; // if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]) return dp[i][j] = func(word1, word2, i-1, j-1, dp);
        else{
            int insert = func(word1, word2, i, j-1, dp);
            int del = func(word1, word2, i-1, j, dp);
            int replace = func(word1, word2, i-1, j-1, dp);
            return dp[i][j] = 1 + min(insert, min(del, replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //return func(word1, word2, n, m, dp); // func(word1, word2, n-1, m-1, dp);
        for(int i=1; i<=n; i++) dp[i][0] = i;
        for(int i=1; i<=m; i++) dp[0][i] = i;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m];
    }
};

// worst Time complexity: 3^n*m