class Solution {
public:
    int func(int n, vector<int>& dp){
        if(n == 0 || n == 1) return dp[n] = n;
        int x;
        if(dp[n-1] != -1) x = dp[n-1];
        else x = func(n-1, dp);
        int y;
        if(dp[n-2] != -1) y = dp[n-2];
        else y = func(n-2, dp);
        return dp[n] = x + y;
    }
    int fib(int n) {
        // if(n == 0 || n == 1)
        //     return n;
        // return fib(n - 1) + fib(n - 2);

        // using dp
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
};