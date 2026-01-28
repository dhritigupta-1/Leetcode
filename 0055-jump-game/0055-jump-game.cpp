class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int b = nums.size() - 1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i] >= b) b = i;
        }
        if(b == 0)return true;
        return false;
    }
};