class Solution {
    public int findMiddleIndex(int[] nums) {
       int n = nums.length;
        int sum = 0;
         for(int i=0; i<nums.length; i++)
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
}