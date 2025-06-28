class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
         for(int i=0; i<n; i++)
         {
            sum += nums[i];
         }
         int lsum = 0;
         int rsum = sum;
        for(int i=0; i<n; i++)
        {
            rsum = rsum - nums[i];
            if(rsum == lsum)
                return i;
            lsum = lsum + nums[i];
        }
         return -1;
    }
};