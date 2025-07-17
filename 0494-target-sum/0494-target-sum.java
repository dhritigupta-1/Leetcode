class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        int targetSum = (target + sum) / 2;
        if((target + sum) % 2 != 0 || target > sum || target < -sum)
            return 0;
        int[][] dp = new int[n + 1][targetSum + 1];
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=targetSum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(nums[i - 1] <= j)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][targetSum];
    }
}