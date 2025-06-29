class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int a = 0, count = 0;
        for(int i=0; i<nums.length; i++)
        {
            if(nums[i] == 1)
            {
                a++;
                count = Math.max(count, a);
            }
            else
                a = 0;
        }
        return count;
    }
}