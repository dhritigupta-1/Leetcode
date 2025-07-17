class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int INF = amount + 1;
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=1; j<=m; j++)
            dp[0][j] = INF;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j - coins[i - 1]]);
            }
        }
        if(dp[n][m] == INF)
            return -1;
        return dp[n][m];
    }
};