class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> DP (n, 0);
        vector<int> new_DP (n,0);
        DP[0] = 0; // dont rob 1st house.
        DP[1] = nums[1];
        new_DP[0] = nums[0]; // dont rob last house.
        new_DP[1] = max(nums[0] , nums[1]);
        for (int i=2; i<nums.size(); i++)
            DP[i] = max(DP[i-1], nums[i]+ DP[i-2]);
        for (int i=2; i<nums.size(); i++)
        {
            if (i== n-1) new_DP[i] = new_DP[i-1]; // dont rob last house.
            else new_DP[i] = max(new_DP[i-1], nums[i]+ new_DP[i-2]);
        }
        return max(DP.back(), new_DP.back());  
    }
};