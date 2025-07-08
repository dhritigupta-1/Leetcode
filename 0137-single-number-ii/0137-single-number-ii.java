class Solution {
    public int singleNumber(int[] nums) {
        int a = 0, b = 0;
        for(int i=0; i<nums.length; i++)
        {
            a ^= nums[i] & ~b;
            b ^= nums[i] & ~a;
        }
        return a;
    }
}