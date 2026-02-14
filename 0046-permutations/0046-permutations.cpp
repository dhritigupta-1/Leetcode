class Solution {
public:
    void Func(vector<int>& nums, vector<int> temp, vector<vector<int>>& res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            Func(nums, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        Func(nums, temp, res);
        return res;
    }
};