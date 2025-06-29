class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int j = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
            else
                count++;
        }
        for(int i = 0; i<count; i++)
        {
            nums[n - 1 - i] = 0;
        }
    }
};