class Solution {
public:
    void Func(vector<int>& nums, vector<int> temp, vector<vector<int>>& res, int start)
    {
        res.push_back(temp);
        for(int i=start; i<nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            Func(nums,temp,res,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>> res;
        Func(nums, temp, res, 0);
        return res;
    }
};