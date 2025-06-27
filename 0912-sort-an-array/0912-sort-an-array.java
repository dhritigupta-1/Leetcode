class Solution {
    public int[] sortArray(int[] nums) {
        for(int i=0; i<nums.length; i++)
        {
            int target = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > target)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = target;
        }
        return nums;
    }
}