class Solution {
public:
    void func(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int> temp, int start){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            if(nums[i] <= target){
                temp.push_back(nums[i]);
                func(nums, target-nums[i], ans, temp, i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(candidates, target, ans, temp, 0);
        return ans;
    }
};