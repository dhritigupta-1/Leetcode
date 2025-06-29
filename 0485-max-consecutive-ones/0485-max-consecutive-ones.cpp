class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                a++;
                count = max(a, count);
            }
            else
                a = 0;
        }
        return count;
    }
};