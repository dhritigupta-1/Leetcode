class Solution {
    public int missingNumber(int[] nums) {
        int i = 0;
        int n = nums.length;
        while(i < n)
        {
            if(nums[i] < n && nums[i] != i)
            {
                int correct = nums[i];
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            }
            else
                i++;
        }
        for(int j=0; j<n; j++)
        {
            if(nums[j] != j)
                return j;
        }
        return n;
    }
}