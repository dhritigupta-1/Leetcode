class Solution {
public:
    void Func(vector<int>& nums, vector<int>temp, vector<vector<int>>& res, int start)
    {
        for(int i=start; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            Func(nums, temp, res, i+1);
            temp.pop_back();
        }
        res.push_back(temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        Func(nums, temp, res, 0);
        return res;
    }
};