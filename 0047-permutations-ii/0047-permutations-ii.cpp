class Solution {
public:
    void Func(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, vector<bool>& used, int start)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            temp.push_back(nums[i]);
            Func(nums, temp, res, used, i+1);
            temp.pop_back();
            used[i] = false;

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool>used(nums.size(), false);
        sort(nums.begin(), nums.end());
        Func(nums, temp, res, used, 0);
        return res;
    }
};