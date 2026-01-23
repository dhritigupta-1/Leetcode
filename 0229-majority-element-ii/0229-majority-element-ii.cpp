class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == cand1)
                count1++;
            else if(nums[i] == cand2)
                count2++;
            else if(count1 == 0) {
                cand1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                cand2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == cand1) count1++; 
            else if(nums[i] == cand2) count2++; 
        }
        if(count1 > nums.size()/3) ans.push_back(cand1);
        if(count2 > nums.size()/3) ans.push_back(cand2);
        return ans;
    }
};