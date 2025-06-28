class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, lead = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(lead == 0)
                candidate = nums[i];
            if(candidate == nums[i])
                lead++;
            else
                lead--;
        }
        return candidate;
    }
};