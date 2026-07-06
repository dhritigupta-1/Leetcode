class Solution {
public:
    static const int MOD = 1e9 + 7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(mx + 1, 0));
        for (int x = 0; x <= nums[0]; x++)  dp[0][x] = 1;
        for (int i = 1; i < n; i++) {
            vector<int> pref(mx + 1, 0);
            pref[0] = dp[i - 1][0];
            for (int v = 1; v <= mx; v++)  pref[v] = (pref[v - 1] + dp[i - 1][v]) % MOD;
            for (int x = 0; x <= nums[i]; x++) {
                int limit = min(x, x + nums[i - 1] - nums[i]);
                if (limit >= 0)  dp[i][x] = pref[limit];
            }
        }
        int ans = 0;
        for (int x = 0; x <= nums[n - 1]; x++)  ans = (ans + dp[n - 1][x]) % MOD;
        return ans;
    }
};