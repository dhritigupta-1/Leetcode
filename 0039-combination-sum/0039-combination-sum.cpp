class Solution {
public:
    void Func(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int target, int start)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start; i<nums.size(); i++)
        {
            if(nums[i] <= target)
            {
                temp.push_back(nums[i]);
                Func(nums, temp, res, target - nums[i], i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        Func(candidates, temp, res, target, 0);
        return res;
    }
};